#include "../sdl2_game_engine/sprites/sprite_definition.h"

const int SCREEN_HEIGHT = 1440;
const int SCREEN_WIDTH = 2560;
const int FPS = 60;
char *WINDOW_TITLE = "Pacman";

int definition_count;
int instance_count;

Engine_Config engine_config;

Sprite_Definition sprite_definitions[MAX_SPRITES];
Sprite_Instance sprite_instances[MAX_SPRITES];
