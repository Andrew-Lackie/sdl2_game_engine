#ifndef TILEMAP_DEFINITION_H
#define TILEMAP_DEFINITION_H

#include "../core/engine_config.h"
#include "../sprites/sprite_definition.h"

typedef enum {
 BLANK_TILE = 0,
 IMG_TILE = 1,
 SPRITE_TILE = 2,
} Tiles;

size_t tile_def_count;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Color color;
} Blank_Tile;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Surface *image;
	SDL_Texture *texture;
	SDL_Rect srcrect;
} Img_Tile;

typedef struct {
	Sprite_Definition *sprite;
	SDL_Rect srcrect;
	int animation;
} Sprite_Tile;

typedef union {
	Blank_Tile blank;
	Img_Tile img;
	Sprite_Tile sprite;
} Tile_Union;

typedef struct {
	Tile_Union tile;
	Tiles type;
} Tile_Type;

typedef struct {
	Tile_Type tile_type;
	bool collision_detection;
} Tile;

Tile_Type *tile_definitions;
size_t total_tile_def;

/*extern Tile *tiles;*/
size_t total_tiles;

int **tile_map_outline;
SDL_Rect **tile_map;

void Init_Tile_Def(size_t);
size_t Blank_Tile_Def(int, int, int, int, SDL_Color);
size_t Img_Tile_Def(int, int, int, int, int, int, char *);
size_t Sprite_Tile_Def(Sprite_Definition *, int);
void Render_Tilemap(char *, int, int);

#endif
