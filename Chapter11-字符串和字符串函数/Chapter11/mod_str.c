//
//  mod_str.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* mod_str.c -- 修改字符串 */
#include "mod_str.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char *);
int PunctCount(const char *);

int mod_str(void)
{
    char line[LIMIT];
    char * find;
    
    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');   // 查找换行符
    if (find)                    // 如果地址不是NULL,
        *find = '\0';            // 用空字符替换
    ToUpper(line);  //转大写
    puts(line);
    printf("That line has %d punctuation characters.\n",
           PunctCount(line));
    
    return 0;
}

//转大写
void ToUpper(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}

//统计标点符号
int PunctCount(const char * str)
{
    int ct = 0;
    while (*str)
    {
        if (ispunct(*str))
            ct++;
        str++;
    }
    
    return ct;
}


