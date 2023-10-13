#ifndef TILEMAP_DEFINITION_H
#define TILEMAP_DEFINITION_H

#include "core/engine_config.h"
#include "sprites/sprite_definition.h"
#include "utils/map_parser.h"

#define BMP 0
#define JPG 1
#define PNG 2

typedef enum {
	BLANK_TILE = 0,
	IMG_TILE = 1,
	SPRITE_TILE = 2,
} Tiles;

extern size_t tile_def_count;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Color color;
	bool collision_detection;
} Blank_Tile;

typedef struct {
	SDL_Rect dimensions;
	SDL_Rect hitbox;
	SDL_Surface *image;
	SDL_Texture *texture;
	SDL_Rect srcrect;
	bool collision_detection;
} Img_Tile;

typedef struct {
	Sprite_Definition *sprite;
	SDL_Rect srcrect;
	SDL_Rect hitbox;
	int animation;
	bool collision_detection;
} Sprite_Tile;

typedef union {
	Blank_Tile blank;
	Img_Tile img;
	Sprite_Tile sprite;
} Tile_Union;

typedef struct {
	Tile_Union tile;
	Tiles type;
	bool collision_detection;
} Tile_Type;

extern Tile_Type *tile_definitions;

extern size_t total_tile_def;
extern size_t total_tiles;

extern SDL_Texture *tile_map_texture;

void Init_Tile_Def(size_t);
size_t Blank_Tile_Def(SDL_Color, bool);
void Create_Img_Texture(char *, int);
size_t Img_Tile_Def(int, int, int, int, bool);
int **Init_Map_Template(char *);
SDL_Rect **Init_Tilemap();
size_t Sprite_Tile_Def(Sprite_Definition *, int, bool);
void Render_Tilemap(char *);

#endif
