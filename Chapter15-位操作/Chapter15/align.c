//
//  align.c
//  Chapter15
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "align.h"
//  align.c -- 对齐

#include <stdio.h>
int align(void)
{
    double dx;
    char ca;
    char cx;
    double dz;
    char cb;
    char _Alignas(double)  cz;
   
    printf("char alignment:   %zd\n", _Alignof(char));
    printf("double alignment: %zd\n", _Alignof(double));
    printf("&dx: %p\n", &dx);
    printf("&ca: %p\n", &ca);
    printf("&cx: %p\n", &cx);
    printf("&dz: %p\n", &dz);
    printf("&cb: %p\n", &cb);
    printf("&cz: %p\n", &cz);
    
    return 0;
}
