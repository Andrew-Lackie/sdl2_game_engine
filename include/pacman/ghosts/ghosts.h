#ifndef GHOSTS_H
#define GHOSTS_H

#include "../../sdl2_game_engine/sprites/sprite_definition.h"

const int GHOST_INSTANCES = 4;
const int GHOST_FRAMES = 2;
const int GHOST_ANIMATION_FREQUENCY = 100;
const float SCALE = 0.4;

Sprite_Animation ghost = {
	.instanceCount = GHOST_INSTANCES,
	.frames = GHOST_FRAMES,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
