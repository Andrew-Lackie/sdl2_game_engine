#include "../include/pacman/pacman_action.h"


void Move_Up(Sprite_Instance *sprite) {
	sprite->position.y -= sprite->ySpeed;
}

void Move_Down(Sprite_Instance *sprite) {
	sprite->position.y += sprite->ySpeed;
}

void Move_Left(Sprite_Instance *sprite) {
	sprite->position.x -= sprite->ySpeed;
}

void Move_Right(Sprite_Instance *sprite) {
	sprite->position.x += sprite->ySpeed;
}
