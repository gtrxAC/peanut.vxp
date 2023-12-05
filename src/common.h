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

#define PALETTE_COUNT 5

typedef enum State {
	ST_MENU,
	ST_RUNNING,
    ST_KEY_MAPPER
} State;

#include "emu.h"
#include "menu.h"
#include "config.h"
#include "keymapper.h"

void set_state(State new_state);
void init_canvas();