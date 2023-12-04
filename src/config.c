#include "common.h"

Config *config;

void default_config() {
    config = malloc(sizeof(Config));
    config->version = 1;
    config->interlace = VM_FALSE;

    if (screen_width >= 320 && screen_height >= 288) {
        config->scale = SCALE_2X;
    } else {
        config->scale = SCALE_1X;
    }

    config->rotation = ROTATION_NONE;
    config->palette[0] = 0xE77C;
    config->palette[1] = 0x9CF0;
    config->palette[2] = 0x52AC;
    config->palette[3] = 0x20A3;

    config->key_up = VM_KEY_UP;
    config->key_down = VM_KEY_DOWN;
    config->key_left = VM_KEY_LEFT;
    config->key_right = VM_KEY_RIGHT;
    config->key_a = VM_KEY_RIGHT_SOFTKEY;
    config->key_b = VM_KEY_LEFT_SOFTKEY;
    config->key_select = VM_KEY_STAR;
    config->key_start = VM_KEY_POUND;
    save_config();
}

void load_config() {
    if (config) free(config);
    vm_ascii_to_ucs2(ucs2_str, 256, "peanut.cfg");

    if (vm_file_get_attributes(ucs2_str) != -1) {
        read_from_file_to_addr("peanut.cfg", &config);
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