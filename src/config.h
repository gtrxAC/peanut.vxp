#pragma once
#include "common.h"

#define CONFIG_VERSION 5

typedef enum ScaleMode {
    SCALE_1X,
    SCALE_1_5X_NEAREST,
    SCALE_1_5X_BILINEAR,
    SCALE_2X,
    SCALE_COUNT,
} ScaleMode;

typedef enum RotationMode {
    ROTATION_NONE
} RotationMode;

typedef struct Config {
    int version;
    VMBOOL interlace;
    ScaleMode scale;
    RotationMode rotation;

    int palette_choice;
    VMUINT16 palette[4];

    int key_up, key_down, key_left, key_right;
    int key_a, key_b, key_start, key_select;

    VMBOOL show_fps;
    VMBOOL basic_touch_labels;
    int key_fast_forward;

    VMBOOL audio;
} Config;

void default_config();
void load_config();
void save_config();

extern Config *config;