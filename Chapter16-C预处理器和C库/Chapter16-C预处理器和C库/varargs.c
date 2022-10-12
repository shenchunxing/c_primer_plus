//
//  varargs.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "varargs.h"
//varargs.c -- 使用可变参数
#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);

int varargs(void)
{
    double s,t;
    
    s = sum(3, 1.1, 2.5, 13.3);
    t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for "
           "sum(3, 1.1, 2.5, 13.3):                %g\n", s);
    printf("return value for "
           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);
    
    return 0;
}

double sum(int lim,...)
{
    va_list ap;                    // 声明一个对象存储参数
    double tot = 0;
    int i;
    
    va_start(ap, lim);             // 把ap初始化为参数列表
    for (i = 0; i < lim; i++)
        tot += va_arg(ap, double); // 访问每一项，每一项都是double类型
    va_end(ap);                    // clean up
    
    return tot;
}
