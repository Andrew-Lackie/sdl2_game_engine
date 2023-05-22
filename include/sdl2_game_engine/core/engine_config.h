#ifndef ENGINE_CONFIG_H
#define ENGINE_CONFIG_H

#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


/********************************************************************************
 																																					.--.
	___            _                     _                _    _       		 |o_o |
 / _ \          | |                   | |              | |  (_)     		 |:_/ |
/ /_\ \_ __   __| |_ __ _____      __ | |     __ _  ___| | ___  ___  		//   \ \
|  _  | '_ \ / _` | '__/ _ \ \ /\ / / | |    / _` |/ __| |/ / |/ _ \	 (|     | )
| | | | | | | (_| | | |  __/\ V  V /  | |___| (_| | (__|   <| |  __/  /'\_   _/`\
\_| |_/_| |_|\__,_|_|  \___| \_/\_/   \_____/\__,_|\___|_|\_\_|\___|  \___)=(___/

********************************************************************************/

typedef struct {

	struct {
		int screenWidth;
		int	screenHeight;
		Uint8 FPS;
		char *windowTitle;
		int tilesX;
		int tilesY;
		int tile_size;
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
