//
//  starsrch.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* starsrch.c -- 使用 strncmp() */
#include "starsrch.h"
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6

//查找以astro开头的字符串数量
int starsrch()
{
    const char * list[LISTSIZE] =
    {
        "astronomy", "astounding",
        "astrophysics", "ostracize",
        "asterism", "astrophobia"
    };
    int count = 0;
    int i;
    
    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i],"astro", 5) == 0)
        {
            printf("Found: %s\n", list[i]);
            count++;
        }
    printf("The list contained %d words beginning"
           " with astro.\n", count);
    
    return 0;
}
