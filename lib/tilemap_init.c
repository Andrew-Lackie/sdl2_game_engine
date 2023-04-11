#include "../include/sdl2_game_engine/map/tilemap_init.h"

void Init_Tile_Def(size_t total) {

  tile_definitions = malloc(sizeof(Tile_Type) * total);
	total_tiles = total;

}

size_t Blank_Tile_Def(int width, int height, SDL_Color color) {
	tile_definitions[tile_def_count].blank.dimensions.x = width;
	tile_definitions[tile_def_count].blank.dimensions.y = height;
	tile_definitions[tile_def_count].blank.color = color;
	tile_definitions[tile_def_count].blank.id = tile_def_count;

	return tile_def_count++;
}

size_t Img_Tile_Def(int width, int height, int hitbox_width, int hitbox_height, char *url) {

	tile_definitions[tile_def_count].img.image = IMG_Load(url);

	if (!tile_definitions[tile_def_count].img.image) return -1;

	tile_definitions[tile_def_count].img.dimensions.x = width;
	tile_definitions[tile_def_count].img.dimensions.y = height;
	tile_definitions[tile_def_count].img.hitbox.x = hitbox_width;
	tile_definitions[tile_def_count].img.hitbox.y = hitbox_height;
	tile_definitions[tile_def_count].img.texture = SDL_CreateTextureFromSurface(GLOBAL_DATA(renderer), sprite_definitions[definition_count].image);

	return tile_def_count++;
}

size_t Sprite_Tile_Def(Sprite_Definition *sprite, int animation) {
	tile_definitions[tile_def_count].sprite.sprite = sprite;
	tile_definitions[tile_def_count].sprite.animation = animation;

	return tile_def_count++;
}
