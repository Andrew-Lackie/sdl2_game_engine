#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <core/engine_config.h>

typedef struct tile_data tile_data;
typedef tile_data* tile_p;

#define TILE_MAX_BYTES 16

struct tile_data {
	tile_p prev;
	char tile[TILE_MAX_BYTES];
};

int **Read_Map_Template(char *);

#endif
