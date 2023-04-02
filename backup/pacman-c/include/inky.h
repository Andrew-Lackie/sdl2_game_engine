#ifndef INKY_H
#define INKY_H

#include "ghosts.h"

Sprite inky;
Vector inkyVector;
SDL_Surface * inkyImage;
SDL_Texture * inkyTexture;
SDL_Rect inkySrc;
SDL_Rect inkyDst;
const int INKY_XPOSITION = 0 + 2*GHOST_WIDTH + GHOST_MARGIN;
const int INKY_YPOSITION = 0;
const int INKY_SPEED = 0;
const char INKY_SPRITE[] = "../assets/inky.png";

Attributes inkyAttributes = {
	.instanceCount = GHOST_INSTANCES,
	.instance = 0,
	.frames = GHOST_FRAMES,
	.isActive = true,
	.url = INKY_SPRITE,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
