//
//  complit.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "complit.h"
/* complit.c -- 复合字面量 */
#include <stdio.h>
#define MAXTITL  41
#define MAXAUTL  31

struct book4 {          // structure template: tag is book
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int complit(void)
{
    struct book4 readfirst;
    int score;
    
    printf("Enter test score: ");
    scanf("%d",&score);
    
    if(score >= 84)
        readfirst = (struct book4) {"Crime and Punishment",
            "Fyodor Dostoyevsky",
            11.25};
    else
        readfirst = (struct book4) {"Mr. Bouncy's Nice Hat",
            "Fred Winsome",
            5.99};
    printf("Your assigned reading:\n");
    printf("%s by %s: $%.2f\n",readfirst.title,
           readfirst.author, readfirst.value);
    
    return 0;
}
