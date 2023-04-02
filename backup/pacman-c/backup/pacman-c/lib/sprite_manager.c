#include "../include/sprite_manager.h"

void ChangeSpriteDir(Sprite *sprite, float elapsed, Dir direction) {
	sprite->attributes->instance = direction;
}
 /* // Player input to move pacman.*/

/*if(keyboardState[SDL_SCANCODE_I]) {*/
	/*sprite->yPosition -= PACMAN_SPEED * elapsed;*/
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

 /*Check if ball rect overlaps with either player rect.*/

/*SDL_Rect ballRect = {*/
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
