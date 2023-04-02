#ifndef PACMAN_H
#define PACMAN_H

#include "../../sprites/sprite_definition.h"

const int PACMAN_SPRITE_WIDTH = 710;
const int PACMAN_SPRITE_HEIGHT = 197;
const int PACMAN_EXPRESSIONS = 3;
const int PACMAN_INITIAL_DIR = 0;
const int PACMAN_INSTANCES = 1;
const int PACMAN_FRAMES = 2;
const int PACMAN_ANIMATION_FREQUENCY = 100;
const float PACMAN_WIDTH = PACMAN_SPRITE_WIDTH / PACMAN_EXPRESSIONS;
const int PACMAN_SCALE = 0.4;

int PACMAN_XPOSITION = 0;
const int PACMAN_YPOSITION = 0;
const int PACMAN_SPEED = 0;

Sprite_Animation pacman = {
	.instanceCount = PACMAN_INSTANCES,
	.frames = PACMAN_FRAMES,
	.scale = PACMAN_SCALE,
	.frequency = PACMAN_ANIMATION_FREQUENCY,
};

#endif
