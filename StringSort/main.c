#include"heapsort_string.h"
#include"mergesort_string.h"
#include"quicksort_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define TEST_DATA_CNT  1000000


int main(){
    char **test_data;
    char line[105];
    char *address;
    int i = 0;
    FILE *fp;
    fp = fopen("dataset2.txt","r");
    test_data = (char **)malloc(sizeof(char *)*(TEST_DATA_CNT+1));
    for(i=0; i<=TEST_DATA_CNT; i++){
        address = (char *)malloc(sizeof(char)*105);
        test_data[i] = address;
    }
    i = 0;
    for(i=0; i<TEST_DATA_CNT;i++){
        fgets(line,105,fp);
        strcpy(test_data[i],line);
    }

/*      Test Performance        */

    struct  timeval start;      
    struct  timeval end;        
    
    unsigned  long diff;       

    gettimeofday(&start, NULL);
    merge_sort_String(test_data,0,TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("MergeSort_String : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);


/*      Test Performance        */ 
    fp = fopen("dataset2.txt","r"); 
    i = 0;
    for(i=0; i<TEST_DATA_CNT;i++){
        fgets(line,105,fp);
        strcpy(test_data[i],line);
    }
    
    gettimeofday(&start, NULL);
    quicksort_String(test_data,0,TEST_DATA_CNT-1);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("QuickSort_String : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);

/*      Test Performance        */
    fp = fopen("dataset2.txt","r");
    for(i=1; i<=TEST_DATA_CNT;i++){
        fgets(line,105,fp);
        strcpy(test_data[i],line);
    }
    gettimeofday(&start, NULL);
    HeapSort_String(test_data,TEST_DATA_CNT);
    gettimeofday(&end, NULL);
    
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("HeapSort_String : \n");    
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);



  return 0;

}
