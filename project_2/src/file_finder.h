//#include <stdlib.h>
//#include <unistd.h> // shell commands?!
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h> // process directories
#include <string.h>

void list_directory(char const*,pid_t*,int*);
int isDirectory(const char*,char*);
int isCSV(char*);
void sort(char*,char*,char*);
