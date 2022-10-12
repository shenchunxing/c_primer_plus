//
//  s_gets.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

#include "s_gets.h"
//打印字符串
char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;
    
    ret_val = fgets(st, n, stdin); //输入
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0') //如果以换行或者空符
            i++;
        if (st[i] == '\n') //换行替换为空符
            st[i] = '\0';
        else // 空符
            while (getchar() != '\n') //过滤多余的字符。
                continue;
    }
    return ret_val;
}
