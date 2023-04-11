#include "../include/sdl2_game_engine/utils/config_parser.h"

config_p Read_Config_File(char *path) {

	FILE *fPtr;

	if ((fPtr = fopen(path, "r+")) == NULL) {
			perror("fopen()");
			return NULL;
	}

	config_p l_addr = NULL;

	while(1) {
		config_p data = NULL;
		if((data = malloc(sizeof(config_data))) == NULL) {
			continue;
		}
		memset(data, 0, sizeof(config_data));
		data->prev = l_addr;

		if (fscanf(fPtr, "%s = %s", &data->key[0], &data->value[0]) != 2) {
			if(feof(fPtr)) {
				break;
			}

			if (strcmp(&(data->key[0]), "#") == 0) {
				while(fgetc(fPtr) != '\n') {
					// go to the end of the line
				}

				free(data);
				continue;
			}

			else {
				perror("fscanf()");
			}
		}
		l_addr = data;
	}

	return l_addr;
}
