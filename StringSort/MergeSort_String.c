#include"mergesort_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define TEST_DATA_CNT 1000000

//merge sort
void merge_String(char *arr[], int head, int mid, int tail){
  int lenA = mid - head + 1;
  int lenB = tail - (mid + 1) + 1;
  char *A[lenA];
  char *B[lenB];

  int i, j, k;
  for(i = 0; i < lenA; i++){
    A[i] = arr[head + i];
  }
  for(j = 0; j < lenB; j++){
    B[j] = arr[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = head;

  while(i < lenA && j < lenB){
    if(strcmp(A[i],B[j])<0  /*A[i] < B[j]*/ ){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];
      j++;
    }
    k++;
  }

  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }

  while(j < lenB){
    arr[k] = B[j];
    j++;
    k++;
  }
}
void merge_sort_String(char *arr[], int head, int tail){
  if(head < tail){
    int mid = (head + tail) / 2;
    merge_sort_String(arr, head, mid);
    merge_sort_String(arr, mid+1, tail);
    merge_String(arr, head, mid, tail);
  }
}
