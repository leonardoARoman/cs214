#include "multiProcCSVsorter.h"
#include "file_handler.h"

/*
  * file_exists takes a char pointer and intends
  * to open a file in read mode "r" given the string
  * pointed by the args and returns true if file exists.
*/
bool file_exists(char *file){
  FILE *stream;
  if ((stream = fopen(file,"r"))!=NULL) {
    printf("file exists!\n");
    fclose((FILE*)stream);
    return true;
  }
  return false;
}
/*
  * counts the number of rows in the file and
  * the number of columns given the edge "e"
  * option and returns the requested number
*/
int get_size(char *file, edge e){
  const int SIZE = 1024;
  int i = 0;// number to be returned
  FILE *stream = fopen(file,"r");
  char buff[SIZE];
  if(e == row){
    while (fgets(buff,SIZE,(FILE*)stream)) {
      i++;// increments as the lenght of rows
    }
    fclose((FILE*)stream);
    return i;// number of rows
  }if (e = column) {
    fgets(buff,SIZE,(FILE*)stream);
    char *next_line = strdup(buff);
    char *token = strtok(next_line,",");
    while (token!=NULL) {
      i++;// increments as the lenght of columns
      token = strtok(NULL,",");
    }
    fclose((FILE*)stream);
    return i;// number of columns
  }
  fclose((FILE*)stream);
  return -1;// error
}
/*
  * Takes an array of strings, a path and the output file name to be.
  * Creates a new file "new_file" using fopen in write "w" mode. Uses
  * a temp char pinter large enough to concatinate a csv string. Traverses
  * the entire array and concatinates all strings using strcat and stores
  * them into the new created file. Memory gets freed and file is closed.
*/
void build_file(String **array,char *path,int size,char *f_name){
  FILE *file_ptr = NULL;// to point to a file address
  int f_name_size = strlen(path)+strlen(f_name)+10;
  char new_file[f_name_size];
  sprintf(new_file,"%s/%s.csv\n",path,f_name);// to create the file path (a/b/c/file.csv)
  file_ptr = fopen(new_file,"w");// to open/create a new file in write mode
  if (file_ptr==NULL) {
    printf("error\n");
    exit(EXIT_FAILURE);
  }
  // temp string to concatinate with more strings
  char *temp = (char*)malloc(sizeof(char)*1024);
  for (int i = 0; i < size; i++) {
    String *str = array[i];
    strcpy(temp,str->string[1]);// store the first element in the array
    strcat(temp,",");// start concatinating with a comma
    for (int j = 1; j < *str->size_t; j++) {
      if (j == *str->size_t-1) {
        strcat(temp,str->string[j]);// last concatinated string
      }else{
        strcat(temp,str->string[j]);// concatinate all strings
      }
    }
    fputs(temp,file_ptr);// store all csv strings in the file one by one.
  }
  fclose(file_ptr);// close new file.
  free(temp);// free temp
}
