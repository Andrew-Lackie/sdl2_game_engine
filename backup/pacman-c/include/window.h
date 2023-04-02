#ifndef WINDOW_H
#define WINDOW_H

#include "pacman.h"

#include "blinky.h"
#include "pinky.h"
#include "inky.h"
#include "clyde.h"

bool Initialize(void) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
			return false;
		}

	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!window) {
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!window) {
		return false;
	}

	/* ------------------------------------ */
	/* Initialize and Render the Characters */
	/* ------------------------------------ */

	////////////
	// GHOSTS //
	////////////

	InitVector(&blinkyVector, BLINKY_XPOSITION, BLINKY_YPOSITION, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, 0, 0);
	InitSprite(&blinky, &blinkyAttributes, &blinkyVector, blinkyImage, blinkyTexture, blinkySrc, blinkyDst);

	InitVector(&pinkyVector, PINKY_XPOSITION, PINKY_YPOSITION, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, 0, 0);
	InitSprite(&pinky, &pinkyAttributes, &pinkyVector, pinkyImage, pinkyTexture, pinkySrc, pinkyDst);

	InitVector(&inkyVector, INKY_XPOSITION, INKY_YPOSITION, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, 0, 0);
	InitSprite(&inky, &inkyAttributes, &inkyVector, inkyImage, inkyTexture, inkySrc, inkyDst);

	InitVector(&clydeVector, CLYDE_XPOSITION, CLYDE_YPOSITION, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, 0, 0);
	InitSprite(&clyde, &clydeAttributes, &clydeVector, clydeImage, clydeTexture, clydeSrc, clydeDst);

	RenderSprite(&blinky);
	RenderSprite(&pinky);
	RenderSprite(&inky);
	RenderSprite(&clyde);

	////////////
	// PACMAN //
	////////////

	InitVector(&pacmanVector, PACMAN_XPOSITION, PACMAN_YPOSITION, PACMAN_WIDTH, PACMAN_SPRITE_HEIGHT, 0, 0);
	InitSprite(&pacman, &blinkyAttributes, &blinkyVector, pacmanImage, pacmanTexture, pacmanSrc, pacmanDst);

	RenderSprite(&pacman);

	return true;
}

bool Update(float elapsed) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	Uint32 ticks = SDL_GetTicks();

	/* --------------------- */
	/* Render the Characters */
	/* --------------------- */

	UpdateSprite(&blinky, ticks);
	UpdateSprite(&pinky, ticks);
	UpdateSprite(&inky, ticks);
	UpdateSprite(&clyde, ticks);

	////////////
	// PACMAN //
	////////////

	UpdateSprite(&pacman, ticks);

	//UpdatePacman(elapsed);
	//RenderPacman();

	SDL_RenderPresent(renderer);
}

void Shutdown(void) {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}


#endif
