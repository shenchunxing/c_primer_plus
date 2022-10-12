//
//  r_drive1.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "r_drive1.h"
/* r_drive1.c -- 测试 rand1() and srand1() */
/* compile with s_and_r.c                  */
#include <stdio.h>
#include <stdlib.h>
extern void srand1(unsigned int x);
extern int rand1(void);

int r_drive1(void)
{
    int count;
    unsigned seed;
    
    printf("Please enter your choice for seed.\n");
    while (scanf("%u", &seed) == 1)
    {
        srand1(seed);    /* 重新设置种子 */
        for (count = 0; count < 5; count++)
            printf("%d\n", rand1());
        printf("Please enter next seed (q to quit):\n");
    }
    printf("Done\n");
    
    return 0;
}
