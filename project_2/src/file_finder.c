/*
  * @author Leonardo Roman.
  * file_finder model is used to find csv files in a directory.
  * Given a directory, file_finder will traverse its content by
  * checking if a file is a file or a directory. If a csv file
  * is found then a new process will be created, using fork(), in
  * order to sort the csv file while the program keeps looking.
  * if a directory is found, then recursivaly will change directory
  * to check for csv files. If other than csv files are found,
  * the file will be ignored.
*/
#include "multiProcCSVsorter.h"
#include "file_finder.h"
#include "mergesort.h"
#include "file_handler.h"
int j = 0;
/*
  * @Param directory          given directory to traverse
  * @Param pid_arr            to store all child pids created
  * @Param size               default array size.
*/
void list_directory(char const *directory,pid_t *pid_arr,int *size){
  printf("cd %s\n",directory);
  struct dirent *curr_dirent;
  DIR *list = opendir(directory);
  if (list == NULL) {
    printf("Error\n");
    return;
  }else{
    while ((curr_dirent = readdir(list))!=NULL) {
      char path[1024];
      sprintf(path,"%s/%s",directory,curr_dirent->d_name); // concatinate string path recursivaly
      // if path is a directory call function recursivaly
      if(isDirectory(path,curr_dirent->d_name)==2){
        // Missing fork() for each directory handling...(should be easy)
        list_directory(path,pid_arr,size);// recursive function call
      }
      // else is a file read/process
      if (isDirectory(path,curr_dirent->d_name)==1 && !isCSV(curr_dirent->d_name)) {
        if (file_exists(path)) {
          pid_t pid = fork();
          if (pid==0) {
            printf("sort %s in process %d j=%d\n",curr_dirent->d_name,getpid(),j);
            sort(path,"director_name",curr_dirent->d_name);
            exit(j);
          }else{
            /*
            if (j == *size) {
              *size = *size * 2;
              printf("new size = %d\n",*size);
              pid_arr = realloc(pid_arr,*size * sizeof(pid_t));
            }
            */
            pid_arr[j] = pid;
          }
          j++;
        }
      }
    }
    closedir(list);
  }
}

int isDirectory(const char* path,char *name){
  struct stat path_stat;
  stat(path,&path_stat);
  // check if valid directory(exclude . and .. dir)
  if (S_ISDIR(path_stat.st_mode)&&name[0]!='.') {
    return 2;
  }
  return S_ISREG(path_stat.st_mode);// return 1 or 0 if not a file
}
/*
  * isCSV takes an arg of format name.extension
  * if extension is "csv" then it returns 0
  * if no extension after "." then -1 for Error
  * and returns 1 if not equal
*/
int isCSV(char *file){
  char *token = strtok(file,".");
  char *str[2];
  int i = 0;
  while (token!=NULL) {
    str[i++] = token;
    token = strtok(NULL,".");
  }
  if (str[0]==NULL||str[1]==NULL) {
    return -1;// error
  }
  return comparator(str[1],"csv"); //returns 0 if equal 1 other wise
}
/*
  * sort function starts the file processing
  * takes a file, a column name and name to
  * to give the new sorted created output file.
*/
void sort(char *file,char *column_name,char *f_name){
  int row_size = get_size(file,row);
  int column_size = get_size(file,column);
  String **array = build_array(file,row_size,column_size);
  int column = get_column(array[0]->string,column_name);
  merge_sort(array,1,row_size-1,column,"NULL");
  //print_list(array,row_size);
  build_file(array,"./output",row_size,f_name);
  destroy(array,row_size);
}
