#include"mergesort.h"
#include"quicksort.h"
#include"heapsort.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define TEST_DATA_CNT 1000000


int main(){
    /*-------------------------------Integer---------------------------------------------*/
    int test_data1[TEST_DATA_CNT];
    char line1[30];
    int i = 0;
    FILE *fp1;
    fp1 = fopen("dataset1.txt","r");
    while( fgets(line1,30,fp1) ){
        test_data1[i] = atoi(line1);
        i++;
    }


/*      Test Performance        */

    struct  timeval start;      
    struct  timeval end;        
    
    unsigned  long diff;       

    gettimeofday(&start, NULL);
    merge_sort(test_data1,0,TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("MergeSort : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);


/*      Test Performance        */ 
    fp1 = fopen("dataset1.txt","r"); 
    i = 0;
    while( fgets(line1,30,fp1) ){
        test_data1[i] = atoi(line1);
        i++;
    }
    
    gettimeofday(&start, NULL);
    quicksort(test_data1,0,TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("QuickSort : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);

/*      Test Performance        */
    fp1 = fopen("dataset1.txt","r");
    i = 0;
    while( fgets(line1,30,fp1) ){
        test_data1[i] = atoi(line1);
        i++;
    }

    gettimeofday(&start, NULL);
    HeapSort(test_data1,TEST_DATA_CNT);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("HeapSort : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);


  return 0;
}