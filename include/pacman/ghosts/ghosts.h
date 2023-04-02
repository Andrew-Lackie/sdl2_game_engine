#ifndef GHOSTS_H
#define GHOSTS_H

#include "../../sdl2_game_engine/sprites/sprite_definition.h"

const int GHOST_SPRITE_WIDTH = 1530;
const int GHOST_SPRITE_HEIGHT = 210;
const int GHOST_HITBOX_XOFF = 0;
const int GHOST_HITBOX_YOFF = 0;
const int GHOST_EXPRESSIONS = 6;
const int GHOST_INSTANCES = 4;
const int GHOST_FRAMES = 2;
const int GHOST_ANIMATION_FREQUENCY = 100;
const int GHOST_WIDTH = GHOST_SPRITE_WIDTH / GHOST_EXPRESSIONS;
const float SCALE = 0.4;

Sprite_Animation ghost = {
	.instanceCount = GHOST_INSTANCES,
	.frames = GHOST_FRAMES,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

typedef enum GhostDir {
	right = 0, down = 1, up = 2, left = 3
} GhostDir;

typedef struct {
	int blinky;
	int pinky;
	int inky;
	int clyde;
} Ghosts;

Ghosts ghosts;
const GhostDir GHOST_INITIAL_DIR = down;

#endif
