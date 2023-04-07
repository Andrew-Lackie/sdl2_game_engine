#ifndef PACMAN_H
#define PACMAN_H

#include "../../sdl2_game_engine/sprites/sprite_definition.h"

const int PACMAN_SPRITE_WIDTH = 3600;
const int PACMAN_SPRITE_HEIGHT = 196;
const int PACMAN_HITBOX_XOFF = 0;
const int PACMAN_HITBOX_YOFF = 0;
const float PACMAN_SPEED = 8;
const int PACMAN_ANIMATIONS = 5;
const int PACMAN_FRAMES = 3;
const int PACMAN_ANIMATION_FREQUENCY = 100;
const float PACMAN_WIDTH = PACMAN_SPRITE_WIDTH / (PACMAN_ANIMATIONS * PACMAN_FRAMES);
const float PACMAN_SCALE = 0.4;
const char PACMAN_SPRITE[] = "../assets/pacman.png";

Sprite_Animation pacman_anim = {
	.instanceCount = PACMAN_ANIMATIONS,
	.frames = PACMAN_FRAMES,
	.scale = PACMAN_SCALE,
	.frequency = PACMAN_ANIMATION_FREQUENCY,
};

#endif
