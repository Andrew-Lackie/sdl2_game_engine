#ifndef HITBOX_MANAGER_H
#define HITBOX_MANAGER_H

#include "../core/engine_config.h"
#include "../sprites/sprite_definition.h"
#include "../physics/vectors.h"

SDL_bool Hitbox_IsColliding(SDL_Rect, SDL_Rect);

Vector2D Hitbox_AutoSet(Sprite_Instance*, SDL_bool, int, Uint8, Uint8, Uint8);

#endif
