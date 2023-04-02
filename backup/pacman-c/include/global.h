#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *currentImage = NULL;

const int WIDTH = 2560;
const int HEIGHT = 1920;
const int FPS = 60;
const float SCALE = 0.4;

bool begin = false;

#endif
