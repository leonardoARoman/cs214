#include "simpleCSVsorter.h"
#include "file_handler.h"

bool file_exists(char *file){
  FILE *stream;
  if ((stream = fopen(file,"r"))!=NULL) {
    printf("file exists!\n");
    fclose((FILE*)stream);
    return true;
  }
  return false;
}

int get_size(char *file, edge e){
  //printf("getting sizes\n");
  const int SIZE = 1024;
  int i = 0;
  FILE *stream = fopen(file,"r");
  char buff[SIZE];
  if(e == row){
    while (fgets(buff,SIZE,(FILE*)stream)) {
      i++;
    }
    fclose((FILE*)stream);
    return i;
  }if (e = column) {
    fgets(buff,SIZE,(FILE*)stream);
    char *next_line = strdup(buff);
    char *token = strtok(next_line,",");
    while (token!=NULL) {
      i++;
      token = strtok(NULL,",");
    }
    fclose((FILE*)stream);
    return i;
  }
  fclose((FILE*)stream);
  return i;
}

void built_file(String **array){

}
