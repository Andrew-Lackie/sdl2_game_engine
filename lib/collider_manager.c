#ifndef COLLIDER_MANAGER_C
#define COLLIDER_MANAGER_C

#include "../include/sdl2_game_engine/collider/collider_manager.h"

SDL_bool Hitbox_IsColliding(SDL_Rect hitbox_a, SDL_Rect hitbox_b) {

		return SDL_HasIntersection(&hitbox_a, &hitbox_b);
}

Vector2D Hitbox_AutoSet(Sprite_Instance *instance, SDL_bool debug, int scale, Uint8 r, Uint8 g, Uint8 b) {

    SDL_Surface *surface = instance->definition->image;

		SDL_LockSurface(surface);

    int w = surface->w / (instance->definition->sprite_animation->frames * instance->definition->sprite_animation->states);
    int h = surface->h;
    int pitch = surface->pitch;
    int color_channels = pitch / surface->w;
    Uint8* pixels = (Uint8*)surface->pixels;

    SDL_UnlockSurface(surface);

    int xmin = w;
    int xmax = 0;
    int ymin = h;
    int ymax = 0;

    printf("BEFORE: \n");
    printf("xmin: %d\n", xmin);
    printf("xmax: %d\n", xmax);
    printf("ymin: %d\n", ymin);
    printf("ymax: %d\n", ymax);

    for(int y = ymax; y < h; y++){
        for(int x = xmax; x < w * color_channels; x += color_channels){

            // pixel must be transparent
            if (pixels[y * (w * color_channels) + x + 0] == b &&
               pixels[y * (w * color_channels) + x + 1] == g &&
               pixels[y * (w * color_channels) + x + 2] == r) {
            }
						else {
                // Update the smallest and largest
                // values of non-transparent pixels
                xmin = fmin(x,xmin);
                xmax = fmax(x,xmax);

                ymin = fmin(ymin,y);
                ymax = fmax(ymax,y);
/*                printf("AFTER: \n");*/
                /*printf("xmin: %d\n", xmin);*/
                /*printf("xmax: %d\n", xmax);*/
                /*printf("ymin: %d\n", ymin);*/
                /*printf("ymax: %d\n", ymax);*/
            }
        }
    }

    // Update our bounding box
    // For width, we need to divide by the pitch of our object
    //
    instance->hitbox.w = ((xmax / color_channels - xmin / color_channels));
    instance->hitbox.h = (ymax - ymin) / scale;
    instance->hitbox.x = instance->position.x;
    instance->hitbox.y = instance->position.y;

    if (debug == SDL_TRUE) {
        SDL_SetRenderDrawColor(GLOBAL_DATA(renderer), 255, 0, 0, 255);
        SDL_RenderDrawRect(GLOBAL_DATA(renderer), &instance->hitbox);
    }

 /*   printf("m_col.w: %d\n", instance->hitbox.w);*/
		/*printf("m_col.h: %d\n", instance->hitbox.h);*/
 /*   printf("m_col.x: %d\n", instance->hitbox.y);*/
		/*printf("m_col.y: %d\n", instance->hitbox.x);*/
		/*printf("\n");*/
	 /* printf("xmin: %d\n", xmin);*/
		/*printf("xmax: %d\n", xmax);*/
		/*printf("ymin: %d\n", ymin);*/
		/*printf("ymax: %d\n", ymax);*/
    /*printf("Color_Channels: %d\n", color_channels);*/

    /*printf("x_coordinate: %d\n y_coordinate: %d\n", instance->hitbox.x, instance->hitbox.y);*/

    Vector2D vector;
    vector.x = xmin / (color_channels * scale);
    vector.y = ymin / scale;
    return vector;
}

#endif
