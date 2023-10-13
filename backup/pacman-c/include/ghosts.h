#ifndef GHOSTS_H
#define GHOSTS_H

#include "global.h"
#include <sprites/sprite_definition.h>

typedef enum GhostDir {
	right = 0, down = 1, up = 2, left = 3
} GhostDir;

const GhostDir GHOST_INITIAL_DIR = down;

GhostDir blinkyDir;
GhostDir pinkyDir;
GhostDir inkyDir;
GhostDir clydeDir;

const int GHOST_SPRITE_WIDTH = 1530;
const int GHOST_SPRITE_HEIGHT = 210;
const int GHOST_EXPRESSIONS = 6;
const int GHOST_INSTANCES = 4;
const int GHOST_FRAMES = 2;
const int GHOST_MARGIN = 5;
const int GHOST_ANIMATION_FREQUENCY = 100;
const int GHOST_WIDTH = GHOST_SPRITE_WIDTH / GHOST_EXPRESSIONS;

#endif
