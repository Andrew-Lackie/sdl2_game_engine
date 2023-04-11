#include "../sdl2_game_engine/sprites/sprite_action.h"
#include "ghosts/blinky.h"
#include "ghosts/pinky.h"
#include "ghosts/inky.h"
#include "ghosts/clyde.h"
#include "ghosts/ghosts.h"

#define MOVE_NONE 0
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define MOVE_UP 3
#define MOVE_DOWN 4

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

/*const int SCREEN_HEIGHT = 1440;*/
/*const int SCREEN_WIDTH = 2560;*/
/*const int FPS = 60;*/
/*char *WINDOW_TITLE = "Pacman";*/
int player_count = 0;

typedef struct {
	int blinky_definition;
	int pinky_definition;
	int inky_definition;
	int clyde_definition;
	int pacman_definition;
} Characters;

Characters characters;

Player *players[MAX_PLAYERS];

Player player;

size_t definition_count;
size_t instance_count;

Engine_Config engine_config;

Sprite_Definition sprite_definitions[MAX_SPRITES];
Sprite_Instance sprite_instances[MAX_SPRITES];
