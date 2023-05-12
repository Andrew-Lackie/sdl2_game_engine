#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {

	struct {
		int screenWidth;
		int	screenHeight;
		Uint8 FPS;
		char *windowTitle;
		int tilesX;
		int tilesY;
	} ini;

	struct {
		SDL_Renderer *renderer;
		SDL_Window *window;
		SDL_Texture *currentImage;
		const Uint8 *keyboardState;
		Uint8 lastTick;
		Uint8 curTick;
		float elapsed;
		struct {
			int x;
			int y;
		} screenCenter;
		SDL_bool begin;
	} global_data;

} Engine_Config;

extern Engine_Config engine_config;

int Screen_Init(char *);

#define GLOBAL_DATA(x) engine_config.global_data.x
#define INI_DATA(x) engine_config.ini.x

#endif
