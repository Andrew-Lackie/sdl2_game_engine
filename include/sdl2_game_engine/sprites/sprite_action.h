#include "../core/engine_config.h"
#include "sprite_definition.h"

#define MAX_PLAYERS 2

extern int player_count;

typedef void (*Operation)(Sprite_Instance *sprite);

typedef struct {
		SDL_Scancode key;
		int anim;
		Operation func;
} Action;

typedef struct {
	Sprite_Instance *sprite;
	int actions_count;
	int struct_size;
	Action actions[];
} Player;

extern Player *players[MAX_PLAYERS];

Player *Create_Player(Player *player, Sprite_Instance *, int);
void Action_Define(int, SDL_Scancode, int, int, Operation);
void Enable_Actions(int);

#define ACTION_KEY(x) GLOBAL_DATA(keyboardState)[player->actions[x].key]
#define ACTION_ANIM(x) player->actions[x].anim
#define ACTION_FUNC(x, y) player->actions[x].func(y)
