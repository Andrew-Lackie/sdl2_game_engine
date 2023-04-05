#include "../include/sdl2_game_engine/sprites/sprite_definition.h"
#include "../include/sdl2_game_engine/window/window.h"

int main() {


	srand((unsigned int)time(NULL));
	atexit(Shutdown);


	if (!Initialize()) {
		exit(1);
	}

	bool quit = false;
	SDL_Event event;

	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					break;
				case SDL_KEYUP:
					GLOBAL_DATA(keyboardState) = NULL;
					break;
			}
		}

		Update();

	}

	Sprite_Destroy();

	SDL_DestroyRenderer(engine_config.global_data.renderer);
	SDL_DestroyWindow(engine_config.global_data.window);
	IMG_Quit();
	SDL_Quit();
}
