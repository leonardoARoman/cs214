#include "simpleCSVsorter.h"
#include "unitest.h"
#include "mergesort.h"

void TEST(){
  printf("Array of Array of strings: testing...\n");
  int size = 5;
  int size1 = 6;
  String str_test[size1];
  String **test  = (String**)malloc(sizeof(str_test));

  char *row1[] = {"leo c","juan","andres","rubens","sofia"};
  char *row2[] = {"leo a","luan","londres","tubens","zofia"};
  char *row3[] = {"peo","kuan","ondres","mubens","qofia"};
  char *row4[] = {"marcos","jose","vinicio","maria","manuel"};
  char *row5[] = {"leo b","vose","jinicio","xaria","banuel"};
  char *row6[] = {"warcos","pose","yinicio","laria","panuel"};
  for (int i = 0; i < 6; i++) {
    char *s[size];
    test[i] = (String*)malloc(sizeof(String));
    test[i]->string = (char**)malloc(sizeof(s));
    test[i]->size_t = (int*)malloc(sizeof(int));
    memcpy(test[i]->size_t,&size,sizeof(int));
  }
  test[0]->string = row1;
  test[1]->string = row2;
  test[2]->string = row3;
  test[3]->string = row4;
  test[4]->string = row5;
  test[5]->string = row6;

  printf("Unsorted Array\n");
  print_list(test,6);
  printf("\nSorting...\n\n");
  merge_sort(test,0,5,0,"Input Array");
  printf("\nSorted Array!\n");
  print_list(test,6);
}

void PROGRESS(String **array,char *side,int l,int r){
  printf("%s: (l=%d,r=%d)\n",side,l,r);
  if (l==0&&r==0) {
    printf("[%d|%p]\n\n",l,array[l]);
    return;
  }
  if (l>0&&r>0&&l==r) {
    printf("[%d|%p]\n\n",l,array[r]);
    return;
  }
  for (int i = l; i < r+1; i++) {
    printf("[%d|%p], ",i,array[i]);
  }
  printf("\n\n");
}
