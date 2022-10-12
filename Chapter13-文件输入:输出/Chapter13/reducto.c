//
//  reducto.c
//  Chapter13
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "reducto.h"
// reducto.c -- 把文件压缩成原来的1/3!
#include <stdio.h>
#include <stdlib.h>    // for exit()
#include <string.h>    // for strcpy(), strcat()
#define LEN 40

int reducto(int argc, char *argv[])
{
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN];    // 存储输出文件名
    int count = 0;
    
    // check for command-line arguments
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // 设置输入
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }
    // 设置输出
    strncpy(name,argv[1], LEN - 5); // 拷贝文件名
    name[LEN - 5] = '\0';
    strcat(name,".red");            // 在文件名后面添加.red
    if ((out = fopen(name, "w")) == NULL) //以写模式打开文件
    {                       // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    // 拷贝数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // 收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
    
    return 0;
}
