#define PEANUT_GB_HEADER_ONLY
#include "common.h"

Config *config;

extern int screen_width;
extern int screen_height;
extern VMWCHAR ucs2_str[128];

const VMUINT16 palettes[PALETTE_COUNT][4] = {
    // Default - https://lospec.com/palette-list/2bit-demichrome
    {0xE77C, 0x9CF0, 0x52AC, 0x20A3},

    // BGB - https://lospec.com/palette-list/nintendo-gameboy-bgb
    {0xDFB9, 0x85ED, 0x332A, 0x00A3},

    // Blue - https://lospec.com/palette-list/eb-gb-plain-flavour
    {0xCF18, 0x9497, 0x5212, 0x18C3},

    // Gold - https://lospec.com/palette-list/gb-chocolate
    {0xFF17, 0xD50A, 0xA2E9, 0x4146},

    // Crimson - https://lospec.com/palette-list/crimson
    {0xEFBA, 0xB268, 0x70C9, 0x1804}
};

void default_config() {
    config = gx_malloc(sizeof(Config));
    if (!config) return;

    config->version = 1;
    config->interlace = VM_FALSE;

    if (screen_width >= 320 && screen_height >= 288) {
        config->scale = SCALE_2X;
    } else {
        config->scale = SCALE_1X;
    }

    config->rotation = ROTATION_NONE;

    int rand_palette = rand() % PALETTE_COUNT;
    config->palette_choice = rand_palette;
    for (int i = 0; i < 4; i++) {
        config->palette[i] = palettes[rand_palette][i];
    }

    config->key_up = VM_KEY_UP;
    config->key_down = VM_KEY_DOWN;
    config->key_left = VM_KEY_LEFT;
    config->key_right = VM_KEY_RIGHT;
    config->key_a = VM_KEY_RIGHT_SOFTKEY;
    config->key_b = VM_KEY_LEFT_SOFTKEY;
    config->key_select = VM_KEY_STAR;
    config->key_start = VM_KEY_POUND;

    config->show_fps = VM_FALSE;
    config->basic_touch_labels = VM_FALSE;
    save_config();
}

void load_config() {
    if (config) free(config);
    vm_ascii_to_ucs2(ucs2_str, 256, "e:\\peanutvxp\\peanut.cfg");

    if (vm_file_get_attributes(ucs2_str) != -1) {
        read_from_file_to_addr("peanut.cfg", (void **)&config);
        if (!config) return;
        log_write("Loaded configuration file");
    } else {
        default_config();
        log_write("Created configuration file");
    }
}

void save_config() {
    write_from_addr_to_file("peanut.cfg", config, sizeof(Config));
    log_write("Saved configuration file");
}