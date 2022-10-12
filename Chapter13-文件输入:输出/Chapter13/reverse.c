//
//  reverse.c
//  Chapter13
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "reverse.h"
/* reverse.c -- 倒序显示文件内容 */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'   /* eof marker in DOS text files */
#define SLEN 81
int reverse(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;
    
    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file,"rb")) == NULL)
    {                               /* 只读模式   */
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    fseek(fp, 0L, SEEK_END);        /* 定位到文件末尾 */
    last = ftell(fp);//定位到文件最后一个字符
    for (count = 1L; count <= last; count++) //倒序
    {
        fseek(fp, -count, SEEK_END); /* 从文件结尾每次回退1个字节      */
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r')  /* MS-DOS files */
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);
    
    return 0;
}
