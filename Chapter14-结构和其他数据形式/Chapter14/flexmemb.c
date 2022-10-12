//
//  flexmemb.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "flexmemb.h"
// flexmemb.c -- 伸缩型数据成员 (C99 feature)
#include <stdio.h>
#include <stdlib.h>

struct flex
{
    size_t count;
    double average;
    double scores[];   // 伸缩型数组成员，大小不确定，导致flex也是不确定的
};

void showFlex(const struct flex * p);

int flexmemb(void)
{
    struct flex * pf1, *pf2;
    int n = 5;
    int i;
    int tot = 0;
    
    // 为结构和数组分配内存
    pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf1->count = n;
    for (i = 0; i < n; i++)
    {
        pf1->scores[i] = 20.0 - i;
        tot += pf1->scores[i];
    }
    pf1->average = tot / n;
    showFlex(pf1);
    
    n = 9;
    tot = 0;
    pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
    pf2->count = n;
    for (i = 0; i < n; i++)
    {
        pf2->scores[i] = 20.0 - i/2.0;
        tot += pf2->scores[i];
    }
    pf2->average = tot / n;
    showFlex(pf2);
    free(pf1);
    free(pf2);
    
    return 0;
}

void showFlex(const struct flex * p)
{
    int i;
    printf("Scores : ");
    for (i = 0; i < p->count; i++)
        printf("%g ", p->scores[i]);
    printf("\nAverage: %g\n", p->average);
}
