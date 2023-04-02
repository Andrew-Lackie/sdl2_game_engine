#ifndef CLYDE_H
#define CLYDE_H

#include "ghosts.h"

Sprite clyde;
Vector clydeVector;
SDL_Surface * clydeImage;
SDL_Texture * clydeTexture;
SDL_Rect clydeSrc;
SDL_Rect clydeDst;
const int CLYDE_XPOSITION = 0 + 3*GHOST_WIDTH + GHOST_MARGIN;
const int CLYDE_YPOSITION = 0;
const int CLYDE_SPEED = 0;
const char CLYDE_SPRITE[] = "../assets/clyde.png";

Attributes clydeAttributes = {
	.instanceCount = GHOST_INSTANCES,
	.instance = 0,
	.frames = GHOST_FRAMES,
	.isActive = true,
	.url = CLYDE_SPRITE,
	.scale = SCALE,
	.frequency = GHOST_ANIMATION_FREQUENCY,
};

#endif
