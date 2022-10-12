//
//  join_chk.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* join_chk.c -- 拼接2个字符串，检查第一个数组的大小 */
#include "join_chk.h"
#include <stdio.h>
#include <string.h>
#define SIZE 30
#define BUGSIZE 13
char * s_gets(char * st, int n);
int join_chk(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    char bug[BUGSIZE];
    int available;
    
    puts("What is your favorite flower?");
    s_gets(flower, SIZE);
    if ((strlen(addon) + strlen(flower) + 1) <= SIZE) //计算空间大小
        strcat(flower, addon);//字符串拼接
    puts(flower);
    puts("What is your favorite bug?");
    s_gets(bug, BUGSIZE);
    available = BUGSIZE - strlen(bug) - 1; //可添加的最大字符数
    strncat(bug, addon, available);//截断
    puts(bug);
    
    return 0;
}

