//
//  repeat.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

/* repeat.c -- 带参数的main函数 */
#include "repeat.h"
#include <stdio.h>
int repeat(int argc, char *argv[])
{
    int count;
    
    printf("The command line has %d arguments:\n", argc - 1);
    for (count = 1; count < argc; count++)
        printf("%d: %s\n", count, argv[count]);
    printf("\n");
    
    return 0;
}
