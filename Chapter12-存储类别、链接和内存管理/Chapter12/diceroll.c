//
//  diceroll.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "diceroll.h"
/* diceroll.c -- 掷骰子模拟程序 */
/* compile with mandydice.c           */
#include <stdio.h>
#include <stdlib.h>           /* for library rand()   */

int roll_count  = 0;          /* 外部链接，统计rollem函数被调用次数     */

//得到一个1~sides的随机数
static int rollem(int sides)  /* 该函数被文件私有 */
{
    int roll;
    
    roll = rand() % sides + 1;
    ++roll_count;             /* 计算函数调用次数 */
    
    return roll;
}

//骰子的数量 ， 每个骰子有几面
int roll_n_dice(int dice, int sides)
{
    int d;
    int total = 0;
    if (sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    
    for (d = 0; d < dice; d++)
        total += rollem(sides);
    
    return total;
}
