#pragma once

#include "vmsys.h"
#include "vmio.h"
#include "vmgraph.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmtimer.h"
#include "vm4res.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "peanut_gb.h"
#include "stb_ds.h"
#include "util.h"

typedef enum State {
	ST_MENU,
	ST_RUNNING
} State;

typedef enum Menu {
    MENU_MAIN,
    MENU_FILE_PICKER,
    MENU_OPTIONS,
    MENU_ABOUT
} Menu;

#include "emu.h"
#include "menu.h"

void set_state(State new_state);