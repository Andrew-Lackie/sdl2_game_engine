#include "../include/window/window.h"
#include "../include/pacman/pacman_init.h"
#include "../include/pacman/pacman_sprites.h"

bool Initialize() {

	if(!Screen_Init(SCREEN_HEIGHT, SCREEN_WIDTH, FPS, WINDOW_TITLE)) {
		return false;
	}

	/* ------------------------------------ */
	/* Initialize and Render the Characters */
	/* ------------------------------------ */


	ghosts.blinky = Sprite_Define(&ghost, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, GHOST_HITBOX_XOFF, GHOST_HITBOX_XOFF, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, BLINKY_SPRITE);
	ghosts.pinky = Sprite_Define(&ghost, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, GHOST_HITBOX_XOFF, GHOST_HITBOX_XOFF, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, PINKY_SPRITE);
	ghosts.inky = Sprite_Define(&ghost, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, GHOST_HITBOX_XOFF, GHOST_HITBOX_XOFF, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, INKY_SPRITE);
	ghosts.clyde = Sprite_Define(&ghost, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, GHOST_HITBOX_XOFF, GHOST_HITBOX_XOFF, GHOST_WIDTH, GHOST_SPRITE_HEIGHT, CLYDE_SPRITE);

	Sprites_Init();

	Sprite_Create_Instance(ghosts.blinky, 0, 0, 0);
	Sprite_Create_Instance(ghosts.pinky, 0, 300, 0);
	Sprite_Create_Instance(ghosts.inky, 0, 600, 0);
	Sprite_Create_Instance(ghosts.clyde, 0, 900, 0);

	Sprite_Draw_Instances();

	return true;
}

void Update() {
	SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), 0, 0, 0, 255);
	SDL_RenderClear(GLOBAL_DATA(renderer));

	GLOBAL_DATA(runTime) = SDL_GetTicks();

	/* -------------------- */
	/* 		Update Sprites 		*/
	/* -------------------- */

	Sprite_Update_Instances();

	SDL_RenderPresent(GLOBAL_DATA(renderer));

}

void Shutdown(void) {
	if (GLOBAL_DATA(renderer)) {
		SDL_DestroyRenderer(GLOBAL_DATA(renderer));
	}

	if (GLOBAL_DATA(window)) {
		SDL_DestroyWindow(GLOBAL_DATA(window));
	}

	SDL_Quit();
}
