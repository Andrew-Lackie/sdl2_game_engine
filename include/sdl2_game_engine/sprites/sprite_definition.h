#ifndef SPRITE_DEFINITION_H
#define SPRITE_DEFINITION_H

#include "../core/engine_config.h"

#define MAX_SPRITES 50

extern int definition_count;
extern int instance_count;

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
	int action;
	SDL_Rect position;
	SDL_bool is_active;
	SDL_bool is_visible;
	SDL_Rect srcrect;
} Sprite_Instance;

extern Sprite_Definition sprite_definitions[MAX_SPRITES];
extern Sprite_Instance sprite_instances[MAX_SPRITES];

int Sprite_Define(Sprite_Animation *sprite_animation, int, int, int, int, int, int, const char*);
void Sprites_Init();
int Sprite_Create_Instance(int, int, int, int);
void Sprite_Draw_Instances();
void Sprite_Update_Instances();
void Sprite_Update_Animation(int, int);
void Sprite_Destroy();

#endif
