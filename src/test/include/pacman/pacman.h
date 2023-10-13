#ifndef PACMAN_H
#define PACMAN_H

#include <sprites/sprite_definition.h>

const float PACMAN_SPEED = 8;
const int PACMAN_ANIMATIONS = 5;
const int PACMAN_FRAMES = 3;
const int PACMAN_ANIMATION_FREQUENCY = 100;
const float PACMAN_SCALE = 0.4;
const char PACMAN_SPRITE[] = "../assets/pacman/pacman.png";

Sprite_Animation pacman_anim = {
	.instanceCount = PACMAN_ANIMATIONS,
	.frames = PACMAN_FRAMES,
	.scale = PACMAN_SCALE,
	.frequency = PACMAN_ANIMATION_FREQUENCY,
};

#endif
