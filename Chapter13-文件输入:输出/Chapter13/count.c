//
//  count.c
//  Chapter13
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "count.h"
/* count.c -- 使用标准IO */
#include <stdio.h>
#include <stdlib.h> // exit() prototype

int count(int argc, char *argv[])
{
    int ch;         // 读取文件时，存储每个字符的地方
    FILE *fp;       // "文件指针"
    unsigned long count = 0;
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) //以只读模式打开文件
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) //获取下一个输入
    {
        putc(ch,stdout);  // 输出每个字符
        count++;
    }
    fclose(fp);//关闭文件
    printf("File %s has %lu characters\n", argv[1], count);
    
    return 0;
}
