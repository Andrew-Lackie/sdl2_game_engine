#include <window/window.h>
#include <physics/collider_manager.h>
#include "../test/include/pacman_init.h"
#include "../test/include/pacman/pacman.h"
#include "../test/include/pacman_action.h"

#include <unistd.h>

bool Initialize() {

		if(!Screen_Init("../pacman.conf")) {
				return false;
		}

		GLOBAL_DATA(lastTick) = SDL_GetTicks();

		/* ----------------------------- */
		/* Initialize and Render the Map */
		/* ----------------------------- */

		Init_Tile_Def(48);

		Create_Img_Texture(map_img_path, BMP);

		bool has_collider = true;
		int tile = 0;

		for (int y = init_pixel_y; y < end_pixel_y; y = y + INI_DATA(tile_size) + margin_pixels) {
				for (int x = init_pixel_x; x < end_pixel_x; x = x + INI_DATA(tile_size) + margin_pixels) {
						if (tile == 45 || tile == 46 || tile == 47) {
								has_collider = false;
						}
						else {
								has_collider = true;
						}
						Img_Tile_Def(x, y, INI_DATA(tile_size), INI_DATA(tile_size), has_collider);
						tile++;
				}
		}

		/* ------------------------------------ */
		/* Initialize and Render the Characters */
		/* ------------------------------------ */

		characters.blinky.def = Sprite_Define(&ghost, BLINKY_SPRITE, 0x00, 0x00, 0x00, SDL_TRUE);
		characters.pinky.def = Sprite_Define(&ghost, PINKY_SPRITE, 0x00, 0x00, 0x00, SDL_TRUE);
		characters.inky.def = Sprite_Define(&ghost, INKY_SPRITE, 0x00, 0x00, 0x00, SDL_TRUE);
		characters.clyde.def = Sprite_Define(&ghost, CLYDE_SPRITE, 0x00, 0x00, 0x00, SDL_TRUE);

		characters.pacman.def = Sprite_Define(&pacman_anim, PACMAN_SPRITE, 0x00, 0x00, 0x00, SDL_TRUE);

		Sprites_Init();

		characters.blinky.inst = Sprite_CreateInstance(characters.blinky.def, 0, 50, 50, 0, 0);
		characters.pinky.inst = Sprite_CreateInstance(characters.pinky.def, 0, 290, 50, 0, 0);
		characters.inky.inst = Sprite_CreateInstance(characters.inky.def, 0, 540, 50, 0, 0);
		characters.clyde.inst = Sprite_CreateInstance(characters.clyde.def, 0, 700, 50, 0, 0);

		characters.pacman.inst= Sprite_CreateInstance(characters.pacman.def, 0, GLOBAL_DATA(screenCenter).x, GLOBAL_DATA(screenCenter).y, PACMAN_SPEED, PACMAN_SPEED);

		Sprite_DrawInstances();

		Create_Player(&player, &sprite_instances[characters.pacman.inst], 4);

		Action_Define(0, SDL_SCANCODE_UP, MOVE_UP, UP, Move_Up);
		Action_Define(0, SDL_SCANCODE_DOWN, MOVE_DOWN, DOWN, Move_Down);
		Action_Define(0, SDL_SCANCODE_LEFT, MOVE_LEFT, LEFT, Move_Left);
		Action_Define(0, SDL_SCANCODE_RIGHT, MOVE_RIGHT, RIGHT, Move_Right);

 /*    printf("hitbox w: %d\n",sprite_instances[characters.pacman.inst].hitbox.w);*/
		 /*printf("hitbox h: %d\n",sprite_instances[characters.clyde.inst].hitbox.h);*/
		 /*printf("sprite w: %d\n",sprite_instances[characters.clyde.inst].position.w);*/
		 /*printf("sprite h: %d\n",sprite_instances[characters.clyde.inst].position.h);*/


		return true;
}

void Update() {
		SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), 0, 0, 0, 255);
		SDL_RenderClear(GLOBAL_DATA(renderer));
		GLOBAL_DATA(keyboardState) = SDL_GetKeyboardState(NULL);

		GLOBAL_DATA(curTick) = SDL_GetTicks();
		float diff = GLOBAL_DATA(curTick) - GLOBAL_DATA(lastTick);
 		GLOBAL_DATA(elapsed) = diff / 1000.f;

		/* ---------------- */
		/* 				Update Map 				*/
		/* ---------------- */

		Render_Tilemap(map_temp_path);

		/* -------------------- */
		/* 				Update Sprites 				*/
		/* -------------------- */

		Enable_Actions(0);

		Sprite_UpdateInstances();

		/* --------------------------*/
		/* 				Collision Detection 		 */
		/* --------------------------*/

		Hitbox_AutoSet(&sprite_instances[characters.pacman.inst], SDL_FALSE, 2, 0x00, 0x00, 0x00);
		Hitbox_AutoSet(&sprite_instances[characters.clyde.inst], SDL_FALSE, 2, 0x00, 0x00, 0x00);

		SDL_bool isColliding = Hitbox_IsColliding(sprite_instances[characters.clyde.inst].hitbox, sprite_instances[characters.pacman.inst].hitbox);

		if (isColliding == true) {
			printf("Is Colliding? : %d\n", isColliding);
		}

		SDL_RenderPresent(GLOBAL_DATA(renderer));

		GLOBAL_DATA(lastTick) = GLOBAL_DATA(curTick);

		if (GLOBAL_DATA(elapsed) < 1 / (INI_DATA(FPS))) {
		}
		else {
				sleep((GLOBAL_DATA(elapsed)) - 1 / (INI_DATA(FPS)));
		}
}

void Shutdown(void) {
		if (GLOBAL_DATA(renderer)) {
				SDL_DestroyRenderer(GLOBAL_DATA(renderer));
		}

		if (GLOBAL_DATA(window)) {
				SDL_DestroyWindow(GLOBAL_DATA(window));
		}

		for (int i = 0; i < MAX_PLAYERS; i++) {
				free(players[i]);
		}

		free(tile_definitions);

		SDL_Quit();
}
