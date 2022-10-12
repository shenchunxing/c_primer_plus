//
//  subst.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "subst.h"
/* subst.c -- substitute in string */
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n",((x)*(x)))

int subst(void)
{
    int y = 5;
    
    PSQR(y);
    PSQR(2 + 4);
    
    return 0;
}
