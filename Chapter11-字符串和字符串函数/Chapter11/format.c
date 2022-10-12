//
//  format.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* format.c -- 格式化一个字符串 */
#include "format.h"
#include <stdio.h>
#define MAX 20
char * s_gets(char * st, int n);

int format(void)
{
    char first[MAX];
    char last[MAX];
    char formal[2 * MAX + 10];
    double prize;
    
    puts("Enter your first name:");
    s_gets(first, MAX);
    puts("Enter your last name:");
    s_gets(last, MAX);
    puts("Enter your prize money:");
    scanf("%lf", &prize);
    sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
    puts(formal);
    
    return 0;
}
