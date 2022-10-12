//
//  generic.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "generic.h"
//  generic.c  -- 定义泛型宏

#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180/(4 * atanl(1)))

// generic square root function
#define SQRT(X) _Generic((X),\
    long double: sqrtl, \
    default: sqrt, \
    float: sqrtf)(X)

// generic sine function, angle in degrees
#define SIN(X) _Generic((X),\
long double: sinl((X)/RAD_TO_DEG),\
default:     sin((X)/RAD_TO_DEG),\
float:       sinf((X)/RAD_TO_DEG)\
)

int generic(void)
{
    float x = 45.0f;
    double xx = 45.0;
    long double xxx =45.0L;
    
    long double y = SQRT(x);
    long double yy= SQRT(xx);
    long double yyy = SQRT(xxx);
    printf("%.17Lf\n", y);   // matches float
    printf("%.17Lf\n", yy);  // matches default
    printf("%.17Lf\n", yyy); // matches long double
    int i = 45;
    yy = SQRT(i);            // matches default
    printf("%.17Lf\n", yy);
    yyy= SIN(xxx);           // matches long double
    printf("%.17Lf\n", yyy);
    
    return 0;
}
