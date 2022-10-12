//
//  copy1.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* copy1.c -- strcpy() 演示 */
#include "copy1.h"
#include <stdio.h>
#include <string.h>  // 使用 strcpy()
#define SIZE 40
#define LIM 5
char * s_gets(char * st, int n);

int copy1(void)
{
    char qwords[LIM][SIZE];
    char temp[SIZE];
    int i = 0;
    
    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strcpy(qwords[i], temp); //拷贝temp到qwords数组中
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);
    
    return 0;
}


#include <string.h>    // 使用 strcpy()
#define WORDS  "beast"
#define SIZE 40

int copy2(void)
{
    const char * orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char * ps;
    
    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig); //从orig中拷贝字符串到copy + 7的位置
    puts(copy);//Be the beast : 空字符覆盖了that的丢一个't'，有了空符，后面的字符串被空符截断了
    puts(ps);//beast . ps指向copy + 7的位置。也就是beast，
    
    printf("%p %p %p\n",orig,ps,copy);
    
    return 0;
}


#include <string.h>  /* 使用 strncpy() */
#define SIZE 40
#define TARGSIZE 7
#define LIM 5
char * s_gets(char * st, int n);

int copy3(void)
{
    char qwords[LIM][TARGSIZE];
    char temp[SIZE];
    int i = 0;
    
    printf("Enter %d words beginning with q:\n", LIM);
    while (i < LIM && s_gets(temp, SIZE))
    {
        if (temp[0] != 'q')
            printf("%s doesn't begin with q!\n", temp);
        else
        {
            strncpy(qwords[i], temp, TARGSIZE - 1); //控制长度
            qwords[i][TARGSIZE - 1] = '\0';
            i++;
        }
    }
    puts("Here are the words accepted:");
    for (i = 0; i < LIM; i++)
        puts(qwords[i]);
    
    return 0;
}
