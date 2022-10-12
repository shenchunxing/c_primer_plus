//
//  mytype.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "mytype.h"
//  mytype.c

#include <stdio.h>

//泛型匹配
#define MYTYPE(X) _Generic((X),\
int: "int",\
float : "float",\
double: "double",\
default: "other"\
)

int mytype(void)
{
    int d = 5;
    
    printf("%s\n", MYTYPE(d));     // d is type int
    printf("%s\n", MYTYPE(2.0*d)); // 2.0* d is type double
    printf("%s\n", MYTYPE(3L));    // 3L is type long
    printf("%s\n", MYTYPE(&d));    // &d is type int *
    return 0;
}
