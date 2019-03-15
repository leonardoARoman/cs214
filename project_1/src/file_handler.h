#include <string.h>
#include <stdio.h>

typedef enum bool {true,false}bool;
typedef enum edge {row,column}edge;

bool file_exists(char*);
int get_size(char*,edge);
int size(FILE*,edge);
void built_file(String**);
