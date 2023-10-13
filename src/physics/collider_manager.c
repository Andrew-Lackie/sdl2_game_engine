#ifndef COLLIDER_MANAGER_C
#define COLLIDER_MANAGER_C

#include <collider/collider_manager.h>

SDL_bool is_colliding(SDL_Rect hitbox_a, SDL_Rect hitbox_b) {

	return SDL_HasIntersection(&hitbox_a, &hitbox_b);
}

#endif
