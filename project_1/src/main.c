#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simpleCSVsorter.h"
#include "file_handler.h"
#include "mergesort.h"
#include "unitest.h"
/*
  To run program use command:
    $cat <file_name> | ./executable c- column_name
  Or command:
    $./executable -c column -d <directory>/<file_name>
*/
int main(int argc, char const *argv[]) {
  //TEST(); // UNCOMMENT if DEBUGING
  String **array = NULL;
  int row_size = 0;
  int column_size = 0;
  int i = -1;
  // If cat <file> | ./executable -c column_name
  if (argv[1][0]=='-'&&argv[1][1]=='c'&&argc==3) {
    row_size = 5044;
    column_size = 28;
    array = toArray(stdin,row_size,column_size);
    i = get_column(array[0]->string,argv[2]);
    if (i == -1) {
      printf("Error: unkown column\n");
      return 0;
    }else{
      merge_sort(array,1,row_size-1,i,"array");
    }
    print_list(array,row_size);
    printf("\nUSING FIRST COMMAND\n");
  }
  // else if $./executable -c column -d <directory>/<file_name>
  else if (argv[3][0]=='-'&&argv[3][1]=='d'&&argc==5) {
    char *file = (char*)malloc(sizeof(char)*strlen(argv[4])+1);
    strcpy(file,argv[4]);
    if(file_exists(file)==true){
      row_size = get_size(file,row);// gets file's row count.
      column_size = get_size(file,column);
    }
    else{
      printf("file doesnt exist.\n");
      return 0;
    }
    if (row_size==0 || column_size==0) {
      return 0;
    }else{
      array = built_array(file,row_size,column_size);
      i = get_column(array[0]->string,argv[2]);
      if (i == -1) {
        printf("Error: unkown column\n");
        return 0;
      }else{
        merge_sort(array,1,row_size-1,i,"array");
      }
      print_list(array,row_size);
      printf("\nUSING SECOND COMMAND\n");
    }
  }
  destroy(array);
  return 0;
}
