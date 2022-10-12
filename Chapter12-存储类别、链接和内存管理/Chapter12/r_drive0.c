//
//  r_drive0.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "r_drive0.h"
/* r_drive0.c -- 测试rand0() 函数 */
/* compile with rand0.c                    */
#include <stdio.h>
extern unsigned int rand0(void);

int r_drive0(void)
{
    int count;
    
    for (count = 0; count < 5; count++)
        printf("%d\n", rand0());
    
    return 0;
}
