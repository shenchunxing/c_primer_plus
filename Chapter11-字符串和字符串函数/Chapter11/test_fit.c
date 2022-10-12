//
//  test_fit.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* test_fit.c -- 使用缩短字符串长度的函数 */
#include "test_fit.h"
#include <stdio.h>
#include <string.h> /* contains string function prototypes */
void fit(char *, unsigned int);

int test_fit(void)
{
    char mesg[] = "Things should be as simple as possible,"
    " but not simpler.";
    
    puts(mesg);
    fit(mesg,38); //限制长度
    puts(mesg);
    puts("Let's look at some more of the string.");
    puts(mesg + 39); //打印从第39个字符开始的字符串
    
    return 0;
}

void fit(char *string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}
