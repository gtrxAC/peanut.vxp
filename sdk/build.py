# ______________________________________________________________________________
#
#  MRE Makefile - resource insertion step (Python)
# ______________________________________________________________________________
# 
import sys, struct, json

def insert_int32(pos, value):
    global axf
    axf = axf[:pos] + struct.pack('<I', value) + axf[pos + 4:]

# Load the compiled AXF (ELF) and app configuration JSON file
with open(sys.argv[1], 'rb') as axf_file:
    axf = axf_file.read()

with open("manifest.json", 'r') as config_file:
    config = json.loads(config_file.read())

# Find the location of the resources in the AXF file by searching for bytes
# I know this is definitely not the best way, but it will do for now
res_offset = axf.find(bytes([0x41,0x70,0x70,0x4C,0x6F,0x67,0x6F,0x2E,0x69,0x6D,0x67,0x00,0x30,0x00,0x00,0x00,0xE0]))
if (res_offset == -1):
    raise RuntimeError("Resource offset not found")

# ______________________________________________________________________________
# 
#  Fix absolute address offsets in the inserted resource file
#  Based on https://github.com/XimikBoda/TinyMRESDK/blob/main/PackApp/main.cpp
# ______________________________________________________________________________
# 
pos = res_offset

while True:
    oldpos = pos
    while axf[pos] != 0:
        pos += 1
    pos += 1

    if axf[pos - 2] == 0:
        break

    offset = int.from_bytes(axf[pos:pos+4], byteorder='little')
    insert_int32(pos, offset + res_offset)
    pos += 8

res2_offset = int.from_bytes(axf[pos:pos+4], byteorder='little')
res2_offset += res_offset
insert_int32(pos, res2_offset)

pos = res2_offset

while True:
    id = int.from_bytes(axf[pos:pos+4], byteorder='little')
    pos += 4

    offset = int.from_bytes(axf[pos:pos+4], byteorder='little')
    insert_int32(pos, offset + res_offset)
    pos += 4

    if id == 0xFFFFFFFF:
        break

# ______________________________________________________________________________
#
#  Tag insertion - helper functions
# ______________________________________________________________________________
# 
tags = []

def append_int32(value):
    global tags
    tags.append(value & 0xFF)
    tags.append((value & 0xFF00) >> 8)
    tags.append((value & 0xFF0000) >> 16)
    tags.append((value & 0xFF000000) >> 24)

def tags_insert_int32(index, value):
    global tags
    for i in range(0, 4): tags.pop(index)
    tags.insert(index, value & 0xFF)
    tags.insert(index + 1, (value & 0xFF00) >> 8)
    tags.insert(index + 2, (value & 0xFF0000) >> 16)
    tags.insert(index + 3, (value & 0xFF000000) >> 24)

def add_int_tag(id, value):
    append_int32(id)
    append_int32(4)
    append_int32(value)

def add_int_array_tag(id, values):
    append_int32(id)
    append_int32(len(values)*4)
    for val in values: append_int32(val)

def add_string_tag(id, value):
    global tags
    append_int32(id)
    append_int32(len(value)*2 + 2)
    tags += bytes(value, "utf_16_le")
    tags.append(0)
    tags.append(0)

def add_ascii_string_tag(id, value):
    global tags
    append_int32(id)
    append_int32(len(value) + 1)
    tags += bytes(value, "ascii")
    tags.append(0)

def add_string_array_tag(id, values):
    global tags
    append_int32(id)
    length_pos = len(tags)
    length = 0
    append_int32(0)
    i = 1
    for val in values:
        encoded = bytes(val, "utf_16_le")
        append_int32(i)
        append_int32(len(encoded) + 2)
        tags += encoded
        tags.append(0)
        tags.append(0)
        length += len(encoded) + 10
        i += 1
    tags_insert_int32(length_pos, length)

# ______________________________________________________________________________
# 
#  Append tags to the end of the file
#  See https://lpcwiki.miraheze.org/wiki/MediaTek_MRE/Tag_format for reference
# ______________________________________________________________________________
# 
tags_pos = len(axf)

add_string_tag(0x01, config["vendor"])
add_string_tag(0x04, config["name"])
add_int_tag(0x05, config["version"])
add_int_tag(0x0f, config["required_ram"])
add_ascii_string_tag(0x12, config["imsi"])
add_string_tag(0x17, config["description"])
add_int_tag(0x18, config["run_in_background"])
add_string_array_tag(0x19, config["app_name_multilang"])

# Permission list
append_int32(0x13)
append_int32(0xD0)
for perm in range(5000, 5026):
    append_int32(perm)
    append_int32(1)

# Constant tags, these usually don't need to be changed
add_int_tag(0x02, 0xFFFFFFFF)  # app ID
add_int_tag(0x03, 1)  # index of key ID, whatever that is
add_int_array_tag(0x06, [0, 0, 0, 0, 0, 0])  # license issue date (unused)
add_int_array_tag(0x07, [0, 0, 0, 0, 0, 0])  # license expiry date
add_int_tag(0x10, 0)  # resolution (not enforced)
add_int_tag(0x11, 8457)  # engine version
add_int_tag(0x16, 1)  # input mode 1
add_int_tag(0x1c, 0)  # doesn't support rotation
add_int_tag(0x21, 6)  # VXP compiled using GCC
add_int_tag(0x22, 0)  # not zlib compressed
add_int_tag(0x23, 1)  # is encoding using UCS2
add_int_tag(0x25, 0)  # system file max size
add_int_tag(0x29, 0)  # uses screen
add_int_tag(0x2a, 0)  # not a VPP file
add_int_tag(0x2c, 0)  # doesn't use push notifications
add_int_tag(0x2d, 0xFFFFFFFF)  # push notification ID (unused)
add_string_tag(0x2e, "")  # push notification sender email
add_int_tag(0x2f, 0)  # doesn't use AB2 formant image (what)
add_int_tag(0x31, 0)  # doesn't use advanced icon format
add_int_tag(0x32, 0)  # doesn't auto-start on power on
add_int_tag(0x33, 0)  # doesn't add shortcut on installation

append_int32(0)  # 8 reserved bytes
append_int32(0)

# Signing key (unused, verification is done using IMSI instead)
tags += bytes([0xB4, 0x56, 0x44, 0x45, 0x31, 0x30])
append_int32(1)
for i in range(0, 16): append_int32(0)

# End of file (tag start position and 8 reserved bytes)
append_int32(tags_pos)
append_int32(0)
append_int32(0)

# Write processed VXP output file
with open(sys.argv[2], 'wb') as vxp_file:
    vxp_file.write(axf)
    vxp_file.write(bytes(tags))