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

# with open("config.json", 'r') as config_file:
#     config = json.loads(config_file.read())

with open("sdk/tags.bin", 'rb') as tags_file: tags = tags_file.read()

# Find the location of the resources in the AXF file by searching for bytes
# I know this is definitely not the best way, but it will do for now
res_offset = axf.find(bytes([0x41,0x70,0x70,0x4C,0x6F,0x67,0x6F,0x2E,0x69,0x6D,0x67,0x00,0x30,0x00,0x00,0x00,0xE0]))

# Write some addresses into the embedded resource file
insert_int32(res_offset + 12, res_offset + 48)  # AppLogo.img
insert_int32(res_offset + 28, res_offset + 2064)  # mre-2.0
insert_int32(res_offset + 37, res_offset + 2064)  # mre-2.0... again?
insert_int32(res_offset + 2068, res_offset + 2096)  # wtf?
insert_int32(res_offset + 2076, res_offset + 2108)
insert_int32(res_offset + 2084, res_offset + 2108)
insert_int32(res_offset + 2076, res_offset + 2120)
insert_int32(res_offset + 2092, res_offset + 2132)

# ______________________________________________________________________________
#
#  Tag insertion
# ______________________________________________________________________________
# 
# Helper functions
def append_int32(value):
    axf.append(value & 0xFF)
    axf.append(value & 0xFF00 >> 8)
    axf.append(value & 0xFF0000 >> 16)
    axf.append(value & 0xFF000000 >> 24)

def add_int_tag(id, value):
    append_int32(id)
    append_int32(4)
    append_int32(value)

def add_string_tag(id, value):
    append_int32(id)
    append_int32(len(value)*2 + 2)
    axf += bytes(value, "utf16_le")


# Append tags to the end of the file
# See https://lpcwiki.miraheze.org/wiki/MAUI_Runtime_Environment/Tag_format for reference
# add_int_tag(0x02, 0xFFFFFFFF)
# add_int_tag(0x03, 1)

# add_int_tag(0x0f, config["required_ram"])
# add_int_tag(0x05, config["version"])

tags_pos = len(axf)
axf += tags
insert_int32(len(axf) - 12, tags_pos)

# Write processed VXP output file
with open(sys.argv[2], 'wb') as vxp_file:
    vxp_file.write(axf)