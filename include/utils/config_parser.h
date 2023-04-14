#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define CONFIG_KEY_MAX_BYTES 128
#define CONFIG_VALUE_MAX_BYTES 512

typedef struct config_data config_data;
typedef config_data* config_p;

struct config_data {
	config_p prev;
	char key[CONFIG_KEY_MAX_BYTES];
	char value[CONFIG_VALUE_MAX_BYTES];
};

config_p Read_Config_File(char*);

#endif
