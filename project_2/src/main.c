#include "file_finder.h"
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
  int size = 5;
  int status;
  pid_t pid[size];
  if (argc==1) {
    // CURRENT DIRECTORY (NO ARG)
    list_directory(".",pid,&size);
  }else{
    // GIVEN DIRECTORY (ARG PASSED)
    list_directory(argv[1],pid,&size);
  }
  // WAIT FOR ALL CHILD PROCESSES
  for (int i = 0; i < size; i++) {
    waitpid(pid[i],&status,0);
    printf("pid #%d exit status %d\n",pid[i],WEXITSTATUS(status));
  }
  // TERMINATE MAIN
  printf("ALL PROCESSES FINISHED OK!\n");
  return 0;
}
