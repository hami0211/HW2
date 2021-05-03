#include"heapsort_string.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#define TEST_DATA_CNT 1000000

void HeapAdjust_String(char *a[],int s,int m)//一次篩選的過程
{
    int j;
    char *rc;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//通過循環沿較大的孩子結點向下篩選
    {
        if(j<m&& strcmp(a[j],a[j+1])<0 /*a[j]<a[j+1]*/ ) j++;//j爲較大的記錄的下標
        if( strcmp(rc,a[j])>0 /*rc>a[j]*/  ) break;
        a[s]=a[j];s=j;
    }
    a[s]=rc;//插入
}
void HeapSort_String(char *a[],int n)
{
    int i,j;
    char *temp;
    for(i=n/2;i>0;i--)//通過循環初始化頂堆
    {
        HeapAdjust_String(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//將堆頂記錄與未排序的最後一個記錄交換
        HeapAdjust_String(a,1,i-1);//重新調整爲頂堆
    }
}