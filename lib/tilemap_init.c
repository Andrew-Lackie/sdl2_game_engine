#include "../include/sdl2_game_engine/map/tilemap_init.h"

void Init_Tile_Def(size_t total) {

  tile_definitions = malloc(sizeof(Tile_Type) * total);
	total_tiles = total;

}

size_t Blank_Tile_Def(int width, int height, int hitbox_width, int hitbox_height, SDL_Color color) {
	tile_definitions[tile_def_count].tile.blank.dimensions.w = width;
	tile_definitions[tile_def_count].tile.blank.dimensions.h = height;
	tile_definitions[tile_def_count].tile.img.hitbox.x = hitbox_width;
	tile_definitions[tile_def_count].tile.img.hitbox.y = hitbox_height;
	tile_definitions[tile_def_count].tile.blank.color = color;

	return tile_def_count++;
}

size_t Img_Tile_Def(int width, int height, int hitbox_width, int src_x_init, int src_y_init, int hitbox_height, char *url) {

	tile_definitions[tile_def_count].tile.img.image = IMG_Load(url);

	if (!tile_definitions[tile_def_count].tile.img.image) return -1;

	tile_definitions[tile_def_count].tile.img.texture = SDL_CreateTextureFromSurface(GLOBAL_DATA(renderer), tile_definitions[tile_def_count].tile.img.image);

	tile_definitions[tile_def_count].tile.img.dimensions.w = width;
	tile_definitions[tile_def_count].tile.img.dimensions.h = height;
	tile_definitions[tile_def_count].tile.img.srcrect.x = src_x_init;
	tile_definitions[tile_def_count].tile.img.srcrect.y = src_y_init;
	tile_definitions[tile_def_count].tile.img.hitbox.x = hitbox_width;
	tile_definitions[tile_def_count].tile.img.hitbox.y = hitbox_height;

	return tile_def_count++;
}

size_t Sprite_Tile_Def(Sprite_Definition *sprite, int animation) {
	tile_definitions[tile_def_count].tile.sprite.sprite = sprite;
	tile_definitions[tile_def_count].tile.sprite.animation = animation;

	return tile_def_count++;
}

void Render_Tilemap(char *path, int tile_count_x, int tile_count_y) {

	tile_map = malloc(tile_count_x * tile_count_y * sizeof(SDL_Rect));

	for (int x = 0; x < tile_count_x; x++) {
		for(int y = 0; y < tile_count_y; y++) {
			tile_map[x][y].x = (INI_DATA(screenWidth) / tile_count_x) * x;
			tile_map[x][y].y = (INI_DATA(screenHeight) / tile_count_y) * y;
		}
	}

	for(int x = 0; x < tile_count_x; x++) {
		for(int y = 0; y < tile_count_y; y++) {

			if (tile_definitions[tile_map_outline[x][y]].type == BLANK_TILE) {

				SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), tile_definitions[tile_def_count].tile.blank.color.r, tile_definitions[tile_def_count].tile.blank.color.g, tile_definitions[tile_def_count].tile.blank.color.b, tile_definitions[tile_def_count].tile.blank.color.a);
        SDL_RenderFillRect(GLOBAL_DATA(renderer), &tile_map[x][y]);

			}

			else if (tile_definitions[tile_map_outline[x][y]].type == IMG_TILE) {

				SDL_RenderCopy(GLOBAL_DATA(renderer), tile_definitions[tile_map_outline[x][y]].tile.img.texture, &tile_definitions[tile_map_outline[x][y]].tile.img.srcrect, &tile_map[x][y]);
			}

			else if (tile_definitions[tile_map_outline[x][y]].type == SPRITE_TILE) {

				SDL_RenderCopy(GLOBAL_DATA(renderer), tile_definitions[tile_map_outline[x][y]].tile.sprite.sprite->texture, &tile_definitions[tile_map_outline[x][y]].tile.sprite.srcrect, &tile_map[x][y]);

			}

		}
	}
}
