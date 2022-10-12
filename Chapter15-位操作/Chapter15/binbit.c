//
//  binbit.c
//  Chapter15
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "binbit.h"
/* binbit.c -- 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h>  // for CHAR_BIT, # of bits per char
char * itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int binbit(void)
{
    //CHAR_BIT:char的位数（每一个字节的大小：8位） * sizeof(int):int类型的大小（4字节） = int类型的位数（32位）
    //1位用于空字符
    char bin_str[CHAR_BIT * sizeof(int) + 1]; //8 * 4 = 32 + 1
    int number;
    
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number,bin_str);
        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");
    
    return 0;
}

/* invert4.c -- 使用位操作显示二进制 */
int invert4(void)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    
    int number;
    
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1)
    {
        itobs(number,bin_str);
        printf("%d is\n", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(number,bin_str));
        putchar('\n');
    }
    puts("Bye!");
    
    return 0;
}

char * itobs(int n, char * ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int); //32 = 8 * 4
    
    for (i = size - 1; i >= 0; i--, n >>= 1) //右移1位
        ps[i] = (01 & n) + '0';//01是8进制的掩码。(01 & n)就是求n的最后一位的值，得到0或者1，但对于字符而言，需要转换成字符，+ ‘0’就可以转成字符
    ps[size] = '\0';//结尾补0
    
    return ps;
}

/* 4位一组显示二进制字符串 */
void show_bstr(const char * str)
{
    int i = 0;
    
    while (str[i])  /* 不是一个空字符串 */
    {
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])
            putchar(' ');
    }
}

int invert_end(int num, int bits)
{
    int mask = 0;
    int bitval = 1; //最后一位设置为1
    
    while (bits-- > 0)//让后n位都设置为1
    {
        mask |= bitval;
        bitval <<= 1;
    }
    
    return num ^ mask;
}
