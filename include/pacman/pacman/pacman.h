#ifndef PACMAN_H
#define PACMAN_H

#include "../../sdl2_game_engine/sprites/sprite_definition.h"
#include "../../sdl2_game_engine/sprites/sprite_movement.h"

const int PACMAN_SPRITE_WIDTH = 710;
const int PACMAN_SPRITE_HEIGHT = 197;
const int PACMAN_HITBOX_XOFF = 0;
const int PACMAN_HITBOX_YOFF = 0;
const float PACMAN_SPEED = 15;
const int PACMAN_EXPRESSIONS = 3;
const int PACMAN_INITIAL_DIR = 0;
const int PACMAN_INSTANCES = 1;
const int PACMAN_FRAMES = 2;
const int PACMAN_ANIMATION_FREQUENCY = 100;
const float PACMAN_WIDTH = PACMAN_SPRITE_WIDTH / PACMAN_EXPRESSIONS;
const float PACMAN_SCALE = 0.4;
const char PACMAN_SPRITE[] = "../assets/pacman.png";

Sprite_Animation pacman_anim = {
	.instanceCount = PACMAN_INSTANCES,
	.frames = PACMAN_FRAMES,
	.scale = PACMAN_SCALE,
	.frequency = PACMAN_ANIMATION_FREQUENCY,
};

Player pacman_player = {
	.left = SDL_SCANCODE_LEFT,
	.right = SDL_SCANCODE_RIGHT,
	.up = SDL_SCANCODE_UP,
	.down = SDL_SCANCODE_DOWN,
};

#endif
