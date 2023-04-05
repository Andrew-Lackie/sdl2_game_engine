#include "pacman/pacman.h"
#include "ghosts/blinky.h"
#include "ghosts/pinky.h"
#include "ghosts/inky.h"
#include "ghosts/clyde.h"
#include "ghosts/ghosts.h"

typedef struct {
	int blinky_definition;
	int pinky_definition;
	int inky_definition;
	int clyde_definition;
	int pacman_definition;
} Characters;

Characters characters;
