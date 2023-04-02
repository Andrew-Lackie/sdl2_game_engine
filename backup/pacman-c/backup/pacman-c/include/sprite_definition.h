#ifndef SPRITE_DEFINITION_H
#define SPRITE_DEFINITION_H

#define MAX _SPRITES 50;

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *currentImage;

typedef enum Dir
{dir1 = 0, dir2 = 1, dir3 = 2, dir4 = 3} Dir;

typedef struct Vector {
	float x;
	float y;
	int frameWidth;
	int frameHeight;
	float xSpeed;
	float ySpeed;
	float len;
} Vector;

typedef struct Attributes {
	int instanceCount;
	int instance;
	int frames;
	bool isActive;
	const char *url;
	float scale;
	Uint32 frequency;
} Attributes;

typedef struct Sprite {
	Attributes *attributes;
	Vector *vector;
	SDL_Surface *image;
	SDL_Texture *texture;
	SDL_Rect srcrect;
	SDL_Rect dstrect;
} Sprite;

void InitVector(Vector *, float, float, int, int, float, float);

void InitSprite(Sprite *, Attributes *attributes, Vector *vector, SDL_Surface *, SDL_Texture *, SDL_Rect, SDL_Rect);

void RenderSprite(Sprite *);

void UpdateSprite(Sprite *, Uint32);

void MoveSprite(Sprite *, int);

void DestroySprite(Sprite *);

#endif
