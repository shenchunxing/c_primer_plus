//
//  friends.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "friends.h"
/* friends.c -- 结构体指针 */
#include <stdio.h>
#define LEN 20

struct names2 {
    char first[LEN];
    char last[LEN];
};

struct guy2 {
    struct names2 handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int friends(void)
{
    struct guy2 fellow[2] = {
        {{ "Ewen", "Villard"},
            "grilled salmon",
            "personality coach",
            68112.00
        },
        {{"Rodney", "Swillbelly"},
            "tripe",
            "tabloid editor",
            432400.00
        }
    };
    struct guy2 * him;    /* here is a pointer to a structure */
    
    printf("address #1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];    /* tell the pointer where to point  */
    printf("pointer #1: %p #2: %p\n", him, him + 1);
    printf("him->income is $%.2f: (*him).income is $%.2f\n",
           him->income, (*him).income);
    him++;               /* point to the next structure      */
    printf("him->favfood is %s:  him->handle.last is %s\n",
           him->favfood, him->handle.last);
    
    return 0;
}
