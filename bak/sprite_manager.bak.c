#include "../include/sdl2_game_engine/sprites/sprite_movement.h"

SDL_Dir Player_Move(Player *player, bool stop) {

	SDL_Dir dir;
	SDL_Anim anim;

	if(GLOBAL_DATA(keyboardState)[player->up.key]) {
		dir = SDL_UP;
		anim = player->up.anim;
	}

	else if(GLOBAL_DATA(keyboardState)[player->down.key]) {
		dir = SDL_DOWN;
		anim = player->down.anim;
	}

	else if(GLOBAL_DATA(keyboardState)[player->left.key]) {
		dir = SDL_LEFT;
		anim = player->left.anim;
	}

	else if(GLOBAL_DATA(keyboardState)[player->right.key]) {
		dir = SDL_RIGHT;
		anim = player->right.anim;
	}

	else {
		dir = player->sprite->dir ;
		if(stop) {
			dir = SDL_NONE;
		}
		anim = player->sprite->animation;
	}

	player->sprite->dir = dir;
	player->sprite->animation = anim;

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
