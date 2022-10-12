//
//  quick_chk.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* quit_chk.c -- 某程序的开始部分 */
#include "quick_chk.h"
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char * s_gets(char * st, int n);

//统计数的字符串个数
int quick_chk(void)
{
    char input[LIM][SIZE];
    int ct = 0;
    
    printf("Enter up to %d lines (type quit to quit):\n", LIM);
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
           strcmp(input[ct],STOP) != 0)
    {
        ct++;
    }
    printf("%d strings entered\n", ct);
    
    return 0;
}
