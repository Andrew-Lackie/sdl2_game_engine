#ifndef HITBOX_MANAGER_H
#define HITBOX_MANAGER_H

#include "../../core/engine_config.h"
#include "../../sprites/sprite_action.h"
#include "../../map/tilemap_init.h"

typedef union {
	Sprite_Instance *sprite;
} Tile;

void hitbox_detector(Sprite_Instance *sprite);

#endif
