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
	SDL_Rect hitbox;
	SDL_Surface *image;
	SDL_Texture *texture;
	Sprite_Animation *sprite_animation;
} Sprite_Definition;

typedef struct {
	Sprite_Definition *definition;
	int animation;
	SDL_Rect position;
	SDL_bool is_active;
	SDL_bool is_visible;
	SDL_Rect srcrect;
	int action;
	float xSpeed; // pixels per second
	float ySpeed; // pixels per second
} Sprite_Instance;

extern Sprite_Definition sprite_definitions[MAX_SPRITES];
extern Sprite_Instance sprite_instances[MAX_SPRITES];

size_t Sprite_Define(Sprite_Animation *, int, int, int, int, int, int, const char*);
void Sprites_Init();
size_t Sprite_Create_Instance(int, int, int, int, float, float);
void Sprite_Draw_Instances();
void Sprite_Update_Instances();
void Sprite_Update_Animation(Sprite_Instance *, int);
void Sprite_Destroy();

#endif
