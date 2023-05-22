#include "../include/sdl2_game_engine/map/tilemap_init.h"
#include "../include/sdl2_game_engine/utils/map_parser.h"

void Init_Tile_Def(size_t total) {

	tile_definitions = malloc(sizeof(Tile_Type) * total);

	total_tiles = total;

}

size_t Blank_Tile_Def(SDL_Color color, bool collision_detection) {

	tile_definitions[tile_def_count].tile.blank.dimensions.w = INI_DATA(screenWidth) / INI_DATA(tilesX);
	tile_definitions[tile_def_count].tile.blank.dimensions.h = INI_DATA(screenHeight) / INI_DATA(tilesY);
	tile_definitions[tile_def_count].tile.blank.color = color;

	tile_definitions[tile_def_count].type = BLANK_TILE;

	tile_definitions[tile_def_count].collision_detection = collision_detection;

	return tile_def_count++;
}

void Create_Img_Texture(char *url, int file_type) {

	SDL_Surface *tile_map_surface;

	if (file_type == BMP) {
		tile_map_surface = IMG_Load(url);
	}

	else if (file_type == PNG || file_type == JPG) {
		tile_map_surface = IMG_Load(url);
	}

	if (tile_map_surface == NULL) exit(1);

	tile_map_texture = SDL_CreateTextureFromSurface(GLOBAL_DATA(renderer), tile_map_surface);
}

size_t Img_Tile_Def(int src_x_init, int src_y_init, int img_width, int img_height, bool collision_detection) {

	tile_definitions[tile_def_count].tile.img.dimensions.w = INI_DATA(screenWidth) / INI_DATA(tilesX);
	tile_definitions[tile_def_count].tile.img.dimensions.h = INI_DATA(screenHeight) / INI_DATA(tilesY);

	tile_definitions[tile_def_count].tile.img.srcrect.x = src_x_init;
	tile_definitions[tile_def_count].tile.img.srcrect.y = src_y_init;
	tile_definitions[tile_def_count].tile.img.srcrect.w = img_width;
	tile_definitions[tile_def_count].tile.img.srcrect.h = img_height;

	tile_definitions[tile_def_count].collision_detection = collision_detection;

	tile_definitions[tile_def_count].type = IMG_TILE;

	return tile_def_count++;
}

size_t Init_Img_Tiles(int end_pixel_x, int end_pixel_y, int margin_pixels, int init_pixel_x, int init_pixel_y) {

	for (int y = init_pixel_y; y < end_pixel_y; y = y + INI_DATA(tile_size) + margin_pixels) {
		for (int x = init_pixel_x; x < end_pixel_x; x = x + INI_DATA(tile_size) + margin_pixels) {
			Img_Tile_Def(x, y, INI_DATA(tile_size), INI_DATA(tile_size), true);
		}
	}
	return tile_def_count;
}

size_t Sprite_Tile_Def(Sprite_Definition *sprite, int animation, bool collision_detection) {
	tile_definitions[tile_def_count].tile.sprite.sprite = sprite;
	tile_definitions[tile_def_count].tile.sprite.animation = animation;

	tile_definitions[tile_def_count].collision_detection = collision_detection;

	tile_definitions[tile_def_count].type = SPRITE_TILE;

	return tile_def_count++;
}

int **Init_Map_Template(char *path) {

	int **tile_map_outline = Read_Map_Template(path);

	return tile_map_outline;
}

SDL_Rect **Init_Tilemap() {

	SDL_Rect **tile_map = malloc(sizeof(SDL_Rect) * INI_DATA(tilesX));

	for (int i = 0; i < INI_DATA(tilesX); i++) {
		tile_map[i] = malloc(sizeof(SDL_Rect) * INI_DATA(tilesY));
	}

	for(int y = 0; y < INI_DATA(tilesY); y++) {
		for (int x = 0; x < INI_DATA(tilesX); x++) {
			tile_map[x][y].x = (INI_DATA(screenWidth) / INI_DATA(tilesX)) * x;
			tile_map[x][y].y = (INI_DATA(screenHeight) / INI_DATA(tilesY)) * y;
			tile_map[x][y].w = INI_DATA(screenWidth) / INI_DATA(tilesX);
			tile_map[x][y].h = INI_DATA(screenHeight) / INI_DATA(tilesY);

		}
	}

	return tile_map;
}

void Render_Tilemap(char *path) {

	int **tile_map_outline = Init_Map_Template(path);

	SDL_Rect **tile_map = Init_Tilemap();

	for(int y = 0; y < INI_DATA(tilesY); y++) {
		for(int x = 0; x < INI_DATA(tilesX); x++) {

			if (tile_definitions[tile_map_outline[x][y]].type == BLANK_TILE) {

				SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), tile_definitions[tile_map_outline[x][y]].tile.blank.color.r, tile_definitions[tile_map_outline[x][y]].tile.blank.color.g, tile_definitions[tile_map_outline[x][y]].tile.blank.color.b, tile_definitions[tile_map_outline[x][y]].tile.blank.color.a);
				SDL_RenderFillRect(GLOBAL_DATA(renderer), &tile_map[x][y]);

			}

			else if (tile_definitions[tile_map_outline[x][y]].type == IMG_TILE) {

				SDL_RenderCopy(GLOBAL_DATA(renderer), tile_map_texture, &tile_definitions[tile_map_outline[x][y] - 1].tile.img.srcrect, &tile_map[x][y]);
			}

			else if (tile_definitions[tile_map_outline[x][y]].type == SPRITE_TILE) {

				SDL_RenderCopy(GLOBAL_DATA(renderer), tile_definitions[tile_map_outline[x][y]].tile.sprite.sprite->texture, &tile_definitions[tile_map_outline[x][y]].tile.sprite.srcrect, &tile_map[x][y]);

			}
		}
	}

	free(tile_map_outline);
	free(tile_map);
}
