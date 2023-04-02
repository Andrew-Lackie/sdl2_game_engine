#ifndef BLINKY_H
#define BLINKY_H

#include "ghosts.h"

const int BLINKY_XPOSITION = 0 + GHOST_MARGIN;
const int BLINKY_YPOSITION = 0;
const int BLINKY_SPEED = 0;
const char BLINKY_SPRITE[] = "../assets/blinky.png";

Sprite blinky;
Vector blinkyVector;
SDL_Surface * blinkyImage;
SDL_Texture * blinkyTexture;
SDL_Rect blinkySrc;
SDL_Rect blinkyDst;

Attributes blinkyAttributes = {
	.instanceCount = GHOST_INSTANCES,
	.instance = 0,
	.frames = GHOST_FRAMES,
	.isActive = true,
	.url = BLINKY_SPRITE,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
