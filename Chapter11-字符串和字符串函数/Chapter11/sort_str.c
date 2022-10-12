//
//  sort_str.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* sort_str.c -- 读入字符串并排序 */
#include "sort_str.h"
#include <stdio.h>
#include <string.h>
#define SIZE 81        /* string length limit, including \0  */
#define LIM 20         /* maximum number of lines to be read */
#define HALT ""        /* null string to stop input          */
void stsrt(char *strings[], int num);/* string-sort function */
char * s_gets(char * st, int n);

int sort_str(void)
{
    char input[LIM][SIZE];     /* 存储输入的数组       */
    char *ptstr[LIM];          /* 内含指针变量的数组 */
    int ct = 0;                /* 输入计数               */
    int k;                     /* 输出计数               */
    
    printf("Input up to %d lines, and I will sort them.\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
           && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];  /* 设置指针指向字符串       */
        ct++;
    }
    stsrt(ptstr, ct);          /* 字符串排序              */
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
        puts(ptstr[k]) ;       /* 排序后的指针            */
    
    return 0;
}

/* 字符串指针排序 */
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    
    for (top = 0; top < num-1; top++)
        for (seek = top + 1; seek < num; seek++)
            if (strcmp(strings[top],strings[seek]) > 0)
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
}


