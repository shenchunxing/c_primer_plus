//
//  variadic.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "variadic.h"
// variadic.c -- 变参宏
#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)

int variadic(void)
{
    double x = 48;
    double y;
    
    y = sqrt(x);
    PR(1, "x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    
    return 0;
}
