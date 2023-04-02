#include "../include/core/engine_config.h"
#include "../include/sprites/sprite_definition.h"

bool Screen_Init(int screenHeight, int screenWidth, int FPS, char *windowTitle) {
	INI_DATA(screenHeight) = screenHeight;
	INI_DATA(screenWidth) = screenWidth;
	INI_DATA(FPS) = FPS;
	INI_DATA(windowTitle) = windowTitle;
	GLOBAL_DATA(screenCenter).x = screenWidth / 2;
	GLOBAL_DATA(screenCenter).y = screenHeight / 2;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
			return false;
		}

	GLOBAL_DATA(window) = SDL_CreateWindow(INI_DATA(windowTitle), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, INI_DATA(screenWidth), INI_DATA(screenHeight), SDL_WINDOW_SHOWN);
	if (!GLOBAL_DATA(window)) {
		return false;
	}

	GLOBAL_DATA(renderer) = SDL_CreateRenderer(GLOBAL_DATA(window), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	return true;
}
