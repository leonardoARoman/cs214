#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*
@Author Leonardo Roman
This file builds an array data structor.
The array is constructed by typedef struct String.
Each String type contains an array of strings, built
from each next_line in the input file. For example,
movie_metadata.csv contains 5044 lines and 27 columns
separated by a comma. Hence the array will contain 5044
String struct type variables of containing an array of 27 strings
*/
typedef struct String{
  char **string;
  int *size_t;
}String;

// Builds an returns an array of type String.
String** toArray(FILE*,int,int);
String** built_array(char*,int,int);
// Takes a line from the file and returs an array of strings separated by a comma.
char** toString(char*,int);
// prints the array of Strings and each string.
void print_list(String**,int);
// free memory when done
void destroy(String**);
