//
//  rand0.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "rand0.h"
/* rand0.c –– 生成随机数            */
/*               uses ANSI C portable algorithm  */
static unsigned long int next = 1;  /* the seed  */

unsigned int rand0(void)
{
    /* magic formula to generate pseudorandom number */
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}
