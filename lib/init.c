#include "../include/sdl2_game_engine/core/engine_config.h"
#include "../include/sdl2_game_engine/sprites/sprite_definition.h"
#include "../include/sdl2_game_engine/utils/config_parser.h"

int Screen_Init(/*int screenHeight, int screenWidth, int FPS, char *windowTitle, */char *config_fPath) {

	config_p data;

	if((data = Read_Config_File(config_fPath)) == NULL) {
		perror("read_config_file()");
    return -1;
	}

	while(1) {
		if(strcmp(data->key, "screen_width") == 0) {
			INI_DATA(screenWidth) = atoi(data->value);
			GLOBAL_DATA(screenCenter).x = atoi(data->value) / 2;
			printf("screen_width: %s\n", data->value);
		}

		else if(strcmp(data->key, "screen_height") == 0) {
			INI_DATA(screenHeight) = atoi(data->value);
			GLOBAL_DATA(screenCenter).y = atoi(data->value) / 2;
			printf("screen_height: %s\n", data->value);
		}

		else if(strcmp(data->key, "fps") == 0) {
			INI_DATA(FPS) = atoi(data->value);
			printf("fps: %s\n", data->value);
		}

		else if(strcmp(data->key, "window_title") == 0) {
			INI_DATA(windowTitle) = data->value;
			printf("window_title: %s\n", data->value);
		}

		if (data->prev != NULL) {
				data = data->prev;
		} else {
				break;
		}
	}

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
