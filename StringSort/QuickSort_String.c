#include"quicksort_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define TEST_DATA_CNT 1000000


//quick sort
void quicksort_String(char *data[], int left, int right)
{
    int i, j;
    char *pivot;

    if (left >= right) { return; }

    pivot = data[left];

    i = left + 1;
    j = right;

    while (1)
    {
        while (i <= right)
        {
            if ( strcmp(data[i],pivot)>0 /*data[i] > pivot*/  )
            {
                break;
            }

            i = i + 1;
        }

        while (j > left)
        {
            if ( strcmp(data[j],pivot)<0 /*data[j] < pivot*/  )
            {
                break;
            }

            j = j - 1;
        }

        if (i > j) { break; }
        swap_String(&data[i], &data[j]);
    }

    swap_String(&data[left], &data[j]);

    quicksort_String(data, left, j - 1);
    quicksort_String(data, j + 1, right);
}

void swap_String(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}
