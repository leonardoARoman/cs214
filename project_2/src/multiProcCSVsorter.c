#include "multiProcCSVsorter.h"

/*
  * returns an array of String struct
  * given a path to a file as input.
*/
String** build_array(char *file,int row_size,int column_size){
  const int SIZE = 1024;
  int i = 0;
  String arr1[row_size];
  String **arr = (String**)malloc(sizeof(arr1));
  FILE *stream = fopen(file,"r");
  char buff[SIZE];

  while (fgets(buff,SIZE,(FILE*)stream)) {
    char *next_line = strdup(buff);
    arr[i] = (String*)malloc(sizeof(String));
    arr[i]->size_t = (int*)malloc(sizeof(int));
    memcpy(arr[i]->size_t,&column_size,sizeof(int));
    arr[i]->string = toString(next_line,column_size);
    i++;
  }
  return arr;
}
/*
  * returns a string of chars
  * before every comma given a
  * csv string.
*/
char** toString(char *str,int size){
  //printf("building string\n");
  char *arr[size];
  char** string_array = (char**)malloc(sizeof(arr));
  char *ptr = (char*)malloc(sizeof(char)*(strlen(str)+1));
  strcpy(ptr,str);
  char *token = strtok(str,",");// token points to the first word b4 a comma
  int i = 0;// Token node number
  int j = 0;// Size of toke list of respective struct node
  // Find all commas and for each missing data create a blank token NONE
  while (*ptr!='\0') {
    j++;
    if (*ptr == ',') {
      if (j>1) {
        // if j>1 then a token was found
        *(string_array+i) = token;
        token = strtok(NULL,",");// move to the next token in the str string
      }else{
        *(string_array+i) = "NONE";
      }
      i++;
      j = 0;
    }
    ptr++;
    if (*ptr == '\0') {
      if (j>1) {
        *(string_array+i) = token;
      }else{
        *(string_array+i) = "NONE";
      }
    }
  }
  return string_array;
}
/*
  * Prints array of array of strings
*/
void print_list(String** ptr,int size){
  printf("printing list...\n");
  for (int i = 0; i < size; i++) {
    String *str = ptr[i];
    //printf("array #%d, at memory location %p, size %d strings\n",i+1,str,*str->size_t);
    for (int j = 0; j < *str->size_t; j++) {
      //printf("string %d: %s\n",j+1,str->string[j]);
      if (j == *str->size_t-1) {
        printf("%s",str->string[j]);
      }else{
        printf("%s,",str->string[j]);
      }
    }
    printf("\n");
  }
}
/*
  * destroys the array of strings
  * freeing memory.
*/
void destroy(String **array,int size){
  for (int i = 0; i < size; i++) {
    free(array[i]);
  }
  free(array);
  printf("\nMemory has been freed.\n");
}
