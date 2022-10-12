//
//  partb.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/10.
//

// partb.c -- 程序的其他部分，和parta一起编译
#include "partb.h"
#include <stdio.h>

extern int count;       // 引用声明，外部链接

static int total = 0;   // static definition, internal linkage
void accumulate(int k); // prototype

void accumulate(int k)  // k has block scope, no linkage
{
    static int subtotal = 0;  // static, no linkage
    
    if (k <= 0)
    {
        printf("loop cycle: %d\n", count);
        printf("subtotal: %d; total: %d\n", subtotal, total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}
