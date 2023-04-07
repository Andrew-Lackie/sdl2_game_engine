#include "../include/sdl2_game_engine/sprites/sprite_action.h"

Player *Create_Player(Player *player, Sprite_Instance *sprite, int actions_count) {

    player = malloc(sizeof(*player) + sizeof(short) + sizeof(Action) * actions_count);

    player->struct_size = (sizeof(*player) + sizeof(short) + sizeof(Action) * actions_count);
    player->actions_count = actions_count;
    player->sprite = sprite;

    players[player_count] = player;

    player_count++;

    return player;
}

void Action_Define(int player_index, SDL_Scancode key, int anim, int action, Operation opt) {
    players[player_index]->actions[action].key = key;
    players[player_index]->actions[action].anim = anim;
    players[player_index]->actions[action].func = opt;
}

void Enable_Actions(int player_index) {
    for (int i = 0; i < players[player_index]->actions_count; i++) {
        if (GLOBAL_DATA(keyboardState)[players[player_index]->actions[i].key]) {
            players[player_index]->sprite->animation = players[player_index]->actions[i].anim;
            players[player_index]->actions[i].func(players[player_index]->sprite);
        }
    }
}
