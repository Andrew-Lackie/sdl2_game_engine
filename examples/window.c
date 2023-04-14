#include "sprite_definition.h"
#include "sprite_action.h"
#include "../include/game_init.h"
#include "../include/character.h"
#include "../include/character_actions.h"

#include <unistd.h>

bool Initialize() {

	if(!Screen_Init("game.conf")) {
		return false;
	}

	GLOBAL_DATA(lastTick) = SDL_GetTicks();

	/* ------------------------------------ */
	/* Initialize and Render the Characters */
	/* ------------------------------------ */

	char_definition = Sprite_Define(&character, WIDTH, HEIGHT, HITBOX_XOFF, HITBOX_XOFF, HITBOX_WIDTH, HITBOX_HEIGHT, "assets/img.png");

	Sprites_Init();

	Sprite_Create_Instance(char_definition, 0, 0, 0, 0, 0);

	int character_instance = Sprite_Create_Instance(char_definition, 0, GLOBAL_DATA(screenCenter).x, GLOBAL_DATA(screenCenter).y, X_SPEED, Y_SPEED);

	Sprite_Draw_Instances();

	Create_Player(&player, &sprite_instances[character_instance], 1);

	Action_Define(0, SDL_SCANCODE_UP, MOVE_UP, UP, Move_Up);
	Action_Define(0, SDL_SCANCODE_DOWN, MOVE_DOWN, DOWN, Move_Down);
	Action_Define(0, SDL_SCANCODE_LEFT, MOVE_LEFT, LEFT, Move_Left);
	Action_Define(0, SDL_SCANCODE_RIGHT, MOVE_RIGHT, RIGHT, Move_Right);

	return true;
}

void Update() {
	SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), 0, 0, 0, 255);
	SDL_RenderClear(GLOBAL_DATA(renderer));
	GLOBAL_DATA(keyboardState) = SDL_GetKeyboardState(NULL);

	GLOBAL_DATA(curTick) = SDL_GetTicks();
	float diff = GLOBAL_DATA(curTick) - GLOBAL_DATA(lastTick);
 	GLOBAL_DATA(elapsed) = diff / 1000.f;

	/* -------------------- */
	/* 		Update Sprites 		*/
	/* -------------------- */

	Enable_Actions(0);

	Sprite_Update_Instances();

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

	SDL_Quit();
}
