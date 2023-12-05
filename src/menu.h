#pragma once
#include "common.h"

typedef enum Menu {
    MENU_MAIN,
    MENU_FILE_PICKER,
    MENU_LOAD_STATE,
    MENU_SAVE_STATE,
    MENU_OPTIONS,
    MENU_ABOUT
} Menu;

void draw_menu();
void set_menu(Menu menu);
void handle_keyevt_menu(VMINT event, VMINT keycode);