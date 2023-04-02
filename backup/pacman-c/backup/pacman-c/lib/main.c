#include "../include/window.h"

int main(int argc, const char *argv[]) {
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
		float elapsed = diff / 1000.0f;
		Update(elapsed);
		lastTick = curTick;

	}

	DestroySprite(&blinky);
	DestroySprite(&pinky);
	DestroySprite(&inky);
	DestroySprite(&clyde);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}
