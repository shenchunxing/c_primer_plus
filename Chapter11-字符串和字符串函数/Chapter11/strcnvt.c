//
//  strcnvt.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* strcnvt.c -- 使用 strtol()  */
#include "strcnvt.h"
#include <stdio.h>
#include <stdlib.h>
#define LIM 30
char * s_gets(char * st, int n);

int strcnvt()
{
    char number[LIM];
    char * end;
    long value;
    
    puts("Enter a number (empty line to quit):");
    while(s_gets(number, LIM) && number[0] != '\0')
    {
        value = strtol(number, &end, 10);  /* base 10 ,把字符串转成long类型*/
        printf("base 10 input, base 10 output: %ld, stopped at %s (%d)\n",
               value, end, *end);
        value = strtol(number, &end, 16);  /* base 16 */
        printf("base 16 input, base 10 output: %ld, stopped at %s (%d)\n",
               value, end, *end);
        puts("Next number:");
    }
    puts("Bye!\n");
    
    return 0;
}
