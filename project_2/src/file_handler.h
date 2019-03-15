#include <string.h>
#include <stdio.h>

typedef enum bool {false,true}bool;
typedef enum edge {row,column}edge;

bool file_exists(char*);
int get_size(char*,edge);
int size(FILE*,edge);
void build_file(String**,char*,int,char*);
