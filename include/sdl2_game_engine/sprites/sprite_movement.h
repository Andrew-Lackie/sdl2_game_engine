#include "../core/engine_config.h"
#include "sprite_definition.h"

typedef struct {
	Sprite_Instance *sprite;
	SDL_Scancode left;
	SDL_Scancode right;
	SDL_Scancode up;
	SDL_Scancode down;
} Player;

SDL_Dir Player_Dir(Player *, bool);

SDL_Dir Sprite_Move(Sprite_Instance *sprite);
