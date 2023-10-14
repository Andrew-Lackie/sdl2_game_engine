#include <utils/map_parser.h>

int **Read_Map_Template(char *path) {

	FILE *file;

  if((file = fopen(path, "r" )) == NULL) {
    printf("Value of errno: %d\n", errno);
    exit(1);
  }

  int rows = INI_DATA(tilesY);
  int columns = INI_DATA(tilesX);

	tile_p l_addr = NULL;
  char c;

  int **arr = malloc(sizeof(int) * columns);

  for (int i = 0; i < columns; i++) {
    arr[i] = malloc(sizeof(int) * rows);
  }



  for(int y = 0; y < rows; y++){
    for(int x = 0; x < columns; x++){
      tile_p data = NULL;
      if((data = malloc(sizeof(tile_data))) == NULL) {
        continue;
      }

      memset(data, 0, sizeof(tile_data));
      data->prev = l_addr;

      if (fscanf(file, "%s", &data->tile[0]) != 0) {
        if(feof(file)) {
          continue;
        }

        while ((c == '\n') || (c == ' ')) {
          c = fgetc(file);
        }
      }

      else {
        perror("fscanf()");
      }

      l_addr = data;

      arr[x][y] = atoi(&l_addr->tile[0]);

      /***((arr + y*rows) + x) = atoi(&l_addr->tile[0]);*/

      free(data);
    }
  }

  fclose(file);

  return arr;
}
