#ifndef MAPS_H
#define MAPS_H

#include "../../sdl2_game_engine/map/tilemap_init.h"

char map_img_path[] = "../assets/map/pacman_map.bmp";
char map_temp_path[] = "../map/pacman_map.txt";

int tiles_y = 3;
int tiles_x = 16;

int margin_pixels = 1;

int tile_width = 8;
int tile_height = 8;

int init_pixel_x = 225;
int init_pixel_y = 27;

int end_pixel_x = 368;
int end_pixel_y = 54;

#endif
