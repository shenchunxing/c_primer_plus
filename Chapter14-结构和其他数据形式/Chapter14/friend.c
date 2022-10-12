//
//  friend.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "friend.h"
// friend.c -- 嵌套结构
#include <stdio.h>
#define LEN 20
const char * msgs[5] =
{
    "    Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together",
    "over a delicious ",
    " and have a few laughs"
};

struct names {                     // first structure
    char first[LEN];
    char last[LEN];
};

struct guy {                       // 嵌套结构
    struct names handle;           // nested structure
    char favfood[LEN];
    char job[LEN];
    float income;
};

int friend_(void)
{
    struct guy fellow = {   // initialize a variable
        { "Ewen", "Villard" },
        "grilled salmon",
        "personality coach",
        68112.00
    };
    
    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.income > 150000.0)
        puts("!!");
    else if (fellow.income > 75000.0)
        puts("!");
    else
        puts(".");
    printf("\n%40s%s\n", " ", "See you soon,");
    printf("%40s%s\n", " ", "Shalala");
    
    return 0;
}
