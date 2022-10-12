//
//  qsorter.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "qsorter.h"
/* qsorter.c -- C语言版本的快速排序 */
#include <stdio.h>
#include <stdlib.h>

#define NUM 40
void fillarray(double ar[], int n);
void showarray(const double ar[], int n);
int mycomp(const void * p1, const void * p2);

int qsorter(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list:");
    showarray(vals, NUM);
    //4个参数：数组、待排序的数量、每个元素占用大小、排序规则
    qsort(vals, NUM, sizeof(double), mycomp);//快速排序
    puts("\nSorted list:");
    showarray(vals, NUM);
    return 0;
}

//生成随机数
void fillarray(double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
        ar[index] = (double)rand()/((double) rand() + 0.1);
}

//打印
void showarray(const double ar[], int n)
{
    int index;
    
    for( index = 0; index < n; index++)
    {
        printf("%9.4f ", ar[index]);
        if (index % 6 == 5)
            putchar('\n');
    }
    if (index % 6 != 0)
        putchar('\n');
}

/* 从小到大排序 */
int mycomp(const void * p1, const void * p2)
{
    /* need to use pointers to double to access values   */
    const double * a1 = (const double *) p1;
    const double * a2 = (const double *) p2;
    
    if (*a1 < *a2)
        return -1;
    else if (*a1 == *a2)
        return 0;
    else
        return 1;
}
