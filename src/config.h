#pragma once
#include "common.h"

typedef enum ScaleMode {
    SCALE_1X,
    SCALE_1_5X,
    SCALE_2X
} ScaleMode;

typedef enum RotationMode {
    ROTATION_NONE
} RotationMode

typedef struct Config {
    int version;
    VMBOOL interlace;
    ScaleMode scale;
    RotationMode rotation;
    VMUINT16 palette[4];

    int key_up, key_down, key_left, key_right;
    int key_a, key_b, key_start, key_select;
} Config;

void default_config();
void load_config();
void save_config();

extern Config *config;