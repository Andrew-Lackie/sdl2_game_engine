#ifndef TILEMAP_DEFINITION_H
#define TILEMAP_DEFINITION_H

#include "../core/engine_config.h"
#include "../sprites/sprite_definition.h"

size_t tile_def_count;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Color color;
	int id;
} Blank_Tile;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Surface *image;
	SDL_Texture *texture;
	SDL_Rect srcrect;
	int id;
} Img_Tile;

typedef struct {
	Sprite_Definition *sprite;
	SDL_Rect srcrect;
	int animation;
	int id;
} Sprite_Tile;

typedef union {
	Blank_Tile blank;
	Img_Tile img;
	Sprite_Tile sprite;
} Tile_Type;

typedef struct {
	Tile_Type tile_type;
	bool collision_detection;
} Tile;

Tile_Type *tile_definitions;
size_t total_tile_def;

/*extern Tile *tiles;*/
size_t total_tiles;

Tile **tile_map;

void Init_Tile_Def(size_t);
size_t Blank_Tile_Def(int, int, SDL_Color);
size_t Img_Tile_Def(int, int, int, int, char *);
size_t Sprite_Tile_Def(Sprite_Definition *, int);

#endif
