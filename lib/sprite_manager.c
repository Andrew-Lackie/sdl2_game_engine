#include "../include/sdl2_game_engine/sprites/sprite_movement.h"

SDL_Dir Player_Dir(Player *player, bool stop) {

	SDL_Dir dir;

	if(GLOBAL_DATA(keyboardState)[player->up]) {
		dir = SDL_UP;
	}

	else if(GLOBAL_DATA(keyboardState)[player->down]) {
		dir = SDL_DOWN;
	}

	else if(GLOBAL_DATA(keyboardState)[player->left]) {
		dir = SDL_LEFT;
	}

	else if(GLOBAL_DATA(keyboardState)[player->right]) {
		dir = SDL_RIGHT;
	}

	else {
		dir = player->sprite->dir ;
		if(stop) {
			dir = SDL_NONE;
		}
	}

	player->sprite->dir = dir;

	return dir;
}

SDL_Dir Sprite_Move(Sprite_Instance *sprite) {


	if(sprite->dir == SDL_UP) {
		sprite->position.y -= sprite->ySpeed;
	}
	else if(sprite->dir == SDL_DOWN) {
		sprite->position.y += sprite->ySpeed;
	}
	else if(sprite->dir == SDL_LEFT) {
		sprite->position.x -= sprite->xSpeed;
	}
	else if(sprite->dir == SDL_RIGHT) {
		sprite->position.x += sprite->xSpeed;
	}

	return sprite->dir;
}
