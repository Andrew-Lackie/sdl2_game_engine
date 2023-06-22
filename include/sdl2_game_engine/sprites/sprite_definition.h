#ifndef SPRITE_DEFINITION_H
#define SPRITE_DEFINITION_H

#include "../core/engine_config.h"

#define MAX_SPRITES 50

extern size_t definition_count;
extern size_t instance_count;

typedef struct {
	int instanceCount;
	int frames;
	float scale;
	Uint32 frequency;
} Sprite_Animation;

typedef struct {
	SDL_Rect dimensions;
	SDL_Surface *image;
	SDL_Texture *texture;
	Sprite_Animation *sprite_animation;
	int pitch;
} Sprite_Definition;

typedef struct {
	Sprite_Definition *definition;
	int action;
	int animation;
	SDL_bool is_active;
	SDL_bool is_visible;
	float xSpeed; // pixels per second
	float ySpeed; // pixels per second
	SDL_Rect position;
	SDL_Rect srcrect;
	SDL_Rect hitbox;
} Sprite_Instance;

/*

	Might be a better implementation?

  typedef struct {
		short len;
		Sprite_Definition arr[];
	} Sprite_Defintions;

*/

extern Sprite_Definition sprite_definitions[MAX_SPRITES];
extern Sprite_Instance sprite_instances[MAX_SPRITES];

size_t Sprite_Define(Sprite_Animation *, const char*);
void Sprites_Init();
size_t Sprite_Create_Instance(int, int, int, int, float, float);
void Sprite_Draw_Instances();
void Sprite_Update_Instances();
void Sprite_Update_Animation(Sprite_Instance *, int);
void Sprite_Destroy();

#endif
