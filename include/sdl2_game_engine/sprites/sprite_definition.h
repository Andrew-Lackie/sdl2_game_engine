#ifndef SPRITE_DEFINITION_H
#define SPRITE_DEFINITION_H

#include "../core/engine_config.h"

#define MAX_SPRITES 50

typedef enum {
	SDL_UP = 0,
	SDL_DOWN = 1,
	SDL_LEFT = 2,
	SDL_RIGHT = 3,
	SDL_NONE = 4,
} SDL_Dir;

typedef enum {
	SDL_ANIM_1 = 0,
	SDL_ANIM_2 = 1,
	SDL_ANIM_3 = 2,
	SDL_ANIM_4 = 3,
	SDL_ANIM_5 = 4,
	SDL_ANIM_6 = 5,
	SDL_ANIM_7 = 6,
	SDL_ANIM_8 = 7,
	SDL_ANIM_9 = 8,
	SDL_ANIM_10 = 10,
} SDL_Animation;

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
	SDL_Animation animation;
	SDL_Rect position;
	SDL_bool is_active;
	SDL_bool is_visible;
	SDL_Rect srcrect;
	SDL_Dir dir;
	float xSpeed; // pixels per second
	float ySpeed; // pixels per second
} Sprite_Instance;

extern Sprite_Definition sprite_definitions[MAX_SPRITES];
extern Sprite_Instance sprite_instances[MAX_SPRITES];

int Sprite_Define(Sprite_Animation *sprite_animation, int, int, int, int, int, int, const char*);
void Sprites_Init();
int Sprite_Create_Instance(int, int, int, int, float, float);
void Sprite_Draw_Instances();
void Sprite_Update_Instances();
void Sprite_Update_Animation(Sprite_Instance *, int);
void Sprite_Destroy();

#endif
