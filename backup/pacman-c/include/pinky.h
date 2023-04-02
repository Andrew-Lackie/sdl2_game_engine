#ifndef PINKY_H
#define PINKY_H

#include "ghosts.h"

Sprite pinky;
Vector pinkyVector;
SDL_Surface * pinkyImage;
SDL_Texture * pinkyTexture;
SDL_Rect pinkySrc;
SDL_Rect pinkyDst;
const int PINKY_XPOSITION = 0 + GHOST_WIDTH + GHOST_MARGIN;
const int PINKY_YPOSITION = 0;
const int PINKY_SPEED = 0;
const char PINKY_SPRITE[] = "../assets/pinky.png";

Attributes pinkyAttributes = {
	.instanceCount = GHOST_INSTANCES,
	.instance = 0,
	.frames = GHOST_FRAMES,
	.isActive = true,
	.url = PINKY_SPRITE,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
