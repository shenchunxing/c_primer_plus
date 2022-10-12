//
//  str_cat.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* str_cat.c -- 字符串拼接 */
#include "str_cat.h"
#include <stdio.h>
#include <string.h>  /* declares the strcat() function */
#define SIZE 80
char * s_gets(char * st, int n);
int str_cat(void)
{
    char flower[SIZE];
    char addon[] = "s smell like old shoes.";
    
    puts("What is your favorite flower?");
    if (s_gets(flower, SIZE))
    {
        strcat(flower, addon); //字符串拼接
        puts(flower);
        puts(addon);
    }
    else
        puts("End of file encountered!");
    puts("bye");


    return 0;
}


