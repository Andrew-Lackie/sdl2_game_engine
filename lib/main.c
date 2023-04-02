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

	Uint32 lastTick = SDL_GetTicks();

	while(!quit) {
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}
		}

		Uint32 curTick = SDL_GetTicks();
		Uint32 diff = curTick - lastTick;
		engine_config.global_data.runTime = diff / 1000.0f;
		Update();
		lastTick = curTick;

	}

	Sprite_Destroy();

	SDL_DestroyRenderer(engine_config.global_data.renderer);
	SDL_DestroyWindow(engine_config.global_data.window);
	IMG_Quit();
	SDL_Quit();
}
