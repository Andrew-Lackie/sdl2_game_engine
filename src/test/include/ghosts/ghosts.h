#ifndef GHOSTS_H
#define GHOSTS_H

#include <sprites/sprite_definition.h>

const int GHOST_STATES = 4;
const int GHOST_FRAMES = 2;
const int GHOST_ANIMATION_FREQUENCY = 100;
const float SCALE = 0.4;

Sprite_Animation ghost = {
	.states = GHOST_STATES,
	.frames = GHOST_FRAMES,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
