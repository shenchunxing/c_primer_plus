//
//  s_and_r.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "s_and_r.h"
/* s_and_r.c -- 包含 rand1() and srand1()    */
/*                uses ANSI C portable algorithm */
static unsigned long int next = 1;  /* the seed  */

int rand1(void)
{
    /* 生成伪随机数的魔术公式 */
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

void srand1(unsigned int seed)
{
    next = seed;
}
