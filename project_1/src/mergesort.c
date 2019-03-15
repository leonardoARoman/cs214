#include "simpleCSVsorter.h"
#include "mergesort.h"
#include "unitest.h"

/******UNCOMMENT ONLY if DEBUGING******/

void merge_sort(String **array,int l,int r,int column,char *side){
  char *left = "LEFT";
  char *right = "RIGHT";

  //PROGRESS(array,side,l,r);
  if (l < r) {
    int m = (l + r)/2;
    merge_sort(array,l,m,column,left);
    merge_sort(array,m+1,r,column,right);
    merge(array,l,m,r,column);
  }
}

void merge(String **arr,int l,int m,int r,int c){
  //printf("MERGING...\n");
  int i, j, k;
  int n1 = (m - l) + 1;
  int n2 = r - m;
  String *left_half[n1];
  String *right_half[n2];

  for (i = 0; i < n1; i++) {
    left_half[i] = arr[l+i];
    //printf("left_half[%d] = %p\n",i,left_half[i]);
  }
  for (j = 0; j < n2; j++) {
    right_half[j] = arr[m+1+j];
    //printf("right_half[%d] = %p\n",i,right_half[i]);
  }

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (comparator(left_half[i]->string[c],
      right_half[j]->string[c])<=0) {
      arr[k] = left_half[i];
      //printf("array[%d]->string[%d] = %s\n\n",k,0,arr[k]->string[c]);
      i++;
    }else{
      arr[k] = right_half[j];
      //printf("array[%d]->string[%d] = %s\n\n",k,0,arr[k]->string[c]);
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = left_half[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = right_half[j];
    j++;
    k++;
  }
}

int get_column(char **str1,char *str2){
  for (int i = 0; i < 27; i++) {
    if (comparator(str1[i],str2)==0) {
      return i;
    }
  }
  return -1;
}

int comparator(char *str1,char *str2){
  // char *str1 = (char*)malloc(sizeof(char)*(strlen(string1)+1));
  // char *str2 = (char*)malloc(sizeof(char)*(strlen(string2)+1));
  // strcpy(str1,string1);
  // strcpy(str2,string2);
  int result = 0;
  //printf("comparing %s with %s\n",str1,str2);
  while ((*str1 != '\0' && *str2 != '\0') && *str1 == *str2) {
    str1++;
    str2++;
  }if (*str1 == *str2) {
    //printf("same\n");
    result = 0;
  }else{
    result = *str1 - *str2;
    // if (result < 0) {
    //   printf("%s is smaller.\n",string1);
    // }else{
    //   printf("%s is smaller.\n",string2);
    // }
  }
  return result;
}
