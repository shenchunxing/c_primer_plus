//
//  parta.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/10.
//
// parta.c --- 不同的存储类别
// compile with partb.c
#include "parta.h"
#include <stdio.h>
void report_count();
void accumulate(int k); //定义在partb.c文件
int count = 0;       // 文件作用域，外部连接

int parta(void)
{
    int value;       // automatic variable
    register int i;  // register variable 
    
    printf("Enter a positive integer (0 to quit): ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count;     // use file scope variable
        for (i = value; i >= 0; i--)
            accumulate(i);
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    
    return 0;
}

void report_count()
{
    printf("Loop executed %d times\n", count);
}
