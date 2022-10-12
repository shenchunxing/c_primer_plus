//
//  put_put.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//
//put_put.c -- 用户自定义输出函数
#include "put_put.h"
#include <stdio.h>
void put1(const char *);
int put2(const char *);

int put_put(void)
{
    put1("If I'd as much money");
    put1(" as I could spend,\n");
    printf("I count %d characters.\n",
           put2("I never would cry old chairs to mend."));//先执行put2
    
    return 0;
}

//打印字符串
void put1(const char * string)
{
    while (*string)  /* same as *string != '\0' */
        putchar(*string++);
}

//统计字符个数
int put2(const char * string)
{
    int count = 0;
    while (*string)
    {
        putchar(*string++);
        count++;
    }
    putchar('\n');
    
    return(count);
}
