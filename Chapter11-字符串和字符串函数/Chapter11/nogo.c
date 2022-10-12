//
//  nogo.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* nogo.c -- 该程序能否正常运行 */
#include "nogo.h"
#include <stdio.h>
#include <string.h>
#define ANSWER "Grant"
#define SIZE 40
char * s_gets(char * st, int n);

int nogo(void)
{
    char try[SIZE];
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (try != ANSWER) //不能这么比较，指针比较的是地址，一直会是false
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");
    
    return 0;
}

int compare(void)
{
    char try[SIZE];
    
    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (strcmp(try,ANSWER) != 0)
    {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");
        
    return 0;
}
