#ifndef PACMAN_H
#define PACMAN_H

#include "global.h"
#include "sprite_definition.h"

/*const int PACMAN_SIZE = 50;*/
/*const int PACMAN_SPEED = 400;*/
/*const int PACMAN_TEXTURE_WIDTH = 0;*/
/*const int PACMAN_TEXTURE_HEIGHT = 0;*/

const int PACMAN_SPRITE_WIDTH = 710;
const int PACMAN_SPRITE_HEIGHT = 197;
const int PACMAN_EXPRESSIONS = 3;
const int PACMAN_INITIAL_DIR = 0;
const int PACMAN_INSTANCES = 1;
const int PACMAN_FRAMES = 2;
const int PACMAN_MARGIN = 2;
const int PACMAN_ANIMATION_FREQUENCY = 100;
const float PACMAN_WIDTH = PACMAN_SPRITE_WIDTH / PACMAN_EXPRESSIONS;

const int PACMAN_XPOSITION = WIDTH / 2 - PACMAN_WIDTH / 2;
const int PACMAN_YPOSITION = 0;
const int PACMAN_SPEED = 0;

Sprite pacman;
Vector pacmanVector;
SDL_Surface * pacmanImage;
SDL_Texture * pacmanTexture;
SDL_Rect pacmanSrc;
SDL_Rect pacmanDst;

Attributes pacmanAttributes = {
	.instanceCount = PACMAN_INSTANCES,
	.instance = 0,
	.frames = PACMAN_FRAMES,
	.url = "../assets/pacman.png",
	.scale = SCALE,
	.frequency = PACMAN_ANIMATION_FREQUENCY,
};

/*Pacman MakePacman(void) {*/
	/*Pacman pacman = {*/
		/*.yPosition = HEIGHT / 2 - PACMAN_SIZE / 2,*/
		/*.xPosition = WIDTH / 2 - PACMAN_SIZE / 2,*/
	/*};*/
	/*return pacman;*/
/*}*/

/*void UpdatePacman(float elapsed) {*/
	/*const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);*/

	/*if(keyboardState[SDL_SCANCODE_SPACE]) {*/
		/*begin = true;*/
	/*}*/

	/*// Player input to move pacman.*/

	/*if(keyboardState[SDL_SCANCODE_I]) {*/
		/*pacman.yPosition -= PACMAN_SPEED * elapsed;*/
	/*}*/

	/*if(keyboardState[SDL_SCANCODE_K]) {*/
		/*pacman.yPosition += PACMAN_SPEED * elapsed;*/
	/*}*/

	/*if(keyboardState[SDL_SCANCODE_J]) {*/
		/*pacman.xPosition -= PACMAN_SPEED * elapsed;*/
	/*}*/

	/*if(keyboardState[SDL_SCANCODE_L]) {*/
		/*pacman.xPosition += PACMAN_SPEED * elapsed;*/
	/*}*/

	/*// Keep pacman in bounds.*/

	/*if (pacman.yPosition > HEIGHT - PACMAN_SIZE / 2) {*/
		/*pacman.yPosition = HEIGHT - PACMAN_SIZE / 2;*/
	/*}*/

	/*if (pacman.yPosition < 0 + PACMAN_SIZE / 2) {*/
		/*pacman.yPosition = 0 + PACMAN_SIZE / 2;*/
	/*}*/

	/*if (pacman.yPosition > HEIGHT - PACMAN_SIZE / 2) {*/
		/*pacman.yPosition = HEIGHT - PACMAN_SIZE / 2;*/
	/*}*/

	/*if (pacman.yPosition < 0 + PACMAN_SIZE / 2) {*/
		/*pacman.yPosition = 0 + PACMAN_SIZE / 2;*/
	/*}*/

	// Check if ball rect overlaps with either player rect.

 /* SDL_Rect ballRect = {*/
		/*.x = ball.x - ball.size / 2,*/
		/*.y = ball.y - ball.size / 2,*/
		/*.w = ball.size,*/
		/*.h = ball.size,*/
	/*};*/

	/*SDL_Rect pacmanRect = {*/
		/*.x = PLAYER_MARGIN,*/
		/*.y = (int)(pacman.yPosition) - PACMAN_SIZE / 2,*/
		/*.w = PLAYER_WIDTH,*/
		/*.h = PACMAN_SIZE,*/
	/*};*/

	/*if (SDL_HasIntersection(&ballRect, &pacmanRect)) {*/
		/*ball.xSpeed = fabs(ball.xSpeed); // Make ball go right.*/
	/*}*/

	/*SDL_Rect pacmanRect = {*/
		/*.x = WIDTH - PLAYER_WIDTH - PLAYER_MARGIN,*/
		/*.y = (int)(pacman.yPosition) - PACMAN_SIZE / 2,*/
		/*.w = PLAYER_WIDTH,*/
		/*.h = PACMAN_SIZE,*/
	/*};*/


	/*if (SDL_HasIntersection(&ballRect, &pacmanRect)) {*/
		/*ball.xSpeed = -ball.xSpeed; // Make ball go left.*/
	/*}*/

//}

/*void RenderPacman(void) {*/
	/*// Render pacman*/
	/*SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);*/
	/*SDL_Rect pacmanRect = {*/
		/*.x = (int)(pacman.xPosition) - PACMAN_SIZE / 2,*/
		/*.y = (int)(pacman.yPosition) - PACMAN_SIZE / 2,*/
		/*.w = PACMAN_SIZE,*/
		/*.h = PACMAN_SIZE,*/
	/*};*/
	/*SDL_RenderFillRect(renderer, &pacmanRect);*/
/*}*/


#endif
