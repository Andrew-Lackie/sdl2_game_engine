#ifndef PACMAN_INIT_H
#define PACMAN_INIT_H

#include <sprites/sprite_action.h>
#include "maps/maps.h"
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

Tile_Type *tile_definitions;

size_t total_tiles;
size_t total_tile_def;
size_t tile_def_count;

SDL_Rect **tile_map;

size_t definition_count;
size_t instance_count;

Engine_Config engine_config;

Sprite_Definition sprite_definitions[MAX_SPRITES];
Sprite_Instance sprite_instances[MAX_SPRITES];

SDL_Texture *tile_map_texture;

#endif
