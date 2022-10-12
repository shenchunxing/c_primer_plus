//
//  funds1.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "funds1.h"
/* funds1.c -- 结构体成员作为参数传递 */
#include <stdio.h>
#define FUNDLEN 50

struct funds {
    char   bank[FUNDLEN];
    double bankfund;
    char   save[FUNDLEN];
    double savefund;
};

double sum(double, double);
double sum2(const struct funds *moolah);
double sum3(struct funds moolah);

int funds1(void)
{
    struct funds stan = {
        "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    };
    
    printf("Stan has a total of $%.2f.\n",
           sum(stan.bankfund, stan.savefund) );
    printf("Stan has a total of $%.2f.\n",
           sum2(&stan) );
    printf("Stan has a total of $%.2f.\n",
           sum3(stan) );
    return 0;
}

/* adds two double numbers */
double sum(double x, double y)
{
    return(x + y);
}

double sum2(const struct funds *moolah)
{
    return moolah->bankfund + moolah->savefund;
}

double sum3(struct funds moolah)
{
    return moolah.bankfund + moolah.savefund;
}

