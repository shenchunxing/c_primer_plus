//
//  main.c
//  Chapter7
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>

// colddays.c -- 找出 0℃ 以下的天数占总天数的百分比
int colddays(void)
{
    const int FREEZING = 0;
    float temperature;
    int cold_days = 0;
    int all_days = 0;
    printf("Enter the list of daily low temperatures.\n");
    printf("Use Celsius, and enter q to quit.\n");
    while (scanf("%f", &temperature) == 1)
    {
        all_days++;
        if (temperature < FREEZING)
            cold_days++;
    }
    if (all_days != 0)
        printf("%d days total: %.1f%% were below freezing.\n",
            all_days, 100.0 * (float)cold_days / all_days);
    if (all_days == 0)
        printf("No data entered.\n");
    return 0;
}

// cypher1.c -- 更改输入，空格不变
#define SPACE ' '    // SPACE 表示单引号-空格-单引号
int cypher1(void)
{
    char ch;
    ch = getchar();    // 读取一个字符
    while (ch != '\n')    // 当一行未结束时
    {
        if (ch == SPACE)    // 留下空格
            putchar(ch);    // 该字符不变
        else
            putchar(ch + 1);    // 改变其他字符
        ch = getchar();    // 获取下一个字符
    }
    putchar(ch);    // 打印换行符
    return 0;
}

// cypher2.c -- 替换输入的字母，非字母字符保持不变
#include <ctype.h>    // 包含 isalpha() 的函数原型
int cypher2(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))    // 如果是一个字符。
            putchar(ch + 1);    // 显示该字符的下一个字符
        else                // 否则，
            putchar(ch);    // 原样显示
    }
    putchar(ch);    // 显示换行符
    return 0;
}

// electric.c -- 计算电费
#define RATE1 0.13230    // 首次使用 360 kwh 的费率
#define RATE2 0.15040    // 接着再使用 108 kwh 的费率
#define RATE3 0.30025    // 接着再使用 252 kwh 的费率
#define RATE4 0.34025    // 使用超过 720 kwh 的费率
#define BREAK1 360.0    // 费率的第 1 个分界点
#define BREAK2 468.0    // 费率的第 2 个分界点
#define BREAK3 720.0    // 费率的第 3 个分界点
// 使用 360 kwh 的费用
#define BASE1 (RATE1 * BREAK1)
// 使用 468 kwh 的费用
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
// 使用 720 kwh 的费率
#define BASE3 (BASE2 + (RATE3 * (BREAK3 - BREAK2)))

int electric(void)
{
    double kwh;        // 使用的千瓦时
    double bill;    // 电费
    printf("Please enter the kwh used.\n");
    scanf("%lf", &kwh);    // %lf 对应 double 类型
    if (kwh <= BREAK1)
        bill = RATE1 * kwh;
    else if (kwh <= BREAK2)    // 360 ~ 468 kwh
        bill = BASE1 + RATE2 * (kwh - BREAK1);
    else if (kwh <= BREAK3) // 468 ~ 720 kwh
        bill = BASE2 + RATE3 * (kwh - BREAK2);
    else                    // 超过 720 kwh
        bill = BASE3 + RATE4 * (kwh - BREAK3);
    printf("The chare for %.1f kwh is $%1.2f.\n", kwh, bill);
    return 0;
}

// divisors.c -- 使用嵌套 if 语句显示一个数的约数
#include <stdbool.h>
int divisors(void)
{
    unsigned long num;    // 待测试的数；
    unsigned long div;    // 可能的约数
    bool isPrime;        // 素数标记
    printf("Please enter an integer for analysis.");
    printf("Enter q to quit.\n");
    while (scanf("%lu", &num) == 1)
    {
        for (div = 2, isPrime = true; (div * div) <= num; div++) {
            if (num % div == 0) { //可以整除，不是素数
                if ((div * div) != num) //不是平方整除
                    printf("%lu is divisible by %lu and %lu.\n",
                        num, div, num / div);
                else //被平方整除
                    printf("%lu is divisible by %lu.\n",
                        num, div);
                isPrime = false;    // 该数不是素数
            }
            
        }
        if (isPrime)
            printf("%lu is prime.\n", num);
        printf("Please enter another integer for analysis;");
        printf("Enter q to quit.\n");
    }
    printf("Bye.\n");
    return 0;
}

// chcount.c -- 使用逻辑与运算符
#define PERIOD '.'
int chcount(void)
{
    char ch;
    int charcount = 0;
    while ((ch = getchar()) != PERIOD)
    {
        if (ch != '"' && ch != '\'')
            charcount++;
    }
    printf("There are %d non-quote characters.\n", charcount);
    return 0;
}

// wordcnt.c -- 统计字符数、单词数、行数
#include <ctype.h>    // 为 isspace() 函数提供原型
#include <stdbool.h>    // 为 bool、true、false 提供定义
#define STOP '|'
int wordcnt(void)
{
    char c;    // 读入字符
    char prev;    // 读入的前一个字符
    long n_chars = 0L;    // 字符数
    int n_lines = 0;    // 行数
    int n_words = 0;    // 单词数
    int p_lines = 0;    // 不完整的行数
    bool inword = false;    // 如果 c 在单词中， inword 等于 true
    printf("Enter text to be analyzed (| to terminate):\n");
    prev = '\n';    // 用于识别完整的行
    while ((c = getchar()) != STOP)
    {
        n_chars++;    // 统计字符
        if (c == '\n')
            n_lines++;    // 统计行
        if (!isspace(c) && !inword)
        {
            inword = true;    // 开始一个新的单词
            n_words++; // 统计单词
        }
        if (isspace(c) && inword) {
            inword = false;    // 达到单词的末尾
        }
        prev = c;    // 保存字符的值
    }
    if (prev != '\n') {
        p_lines = 1;
    }
    printf("characters = %ld, words = %d, lines = %d, ",
        n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
    return 0;
}

/* paint.c -- 使用条件运算符 */
#define COVERAGE 350    // 每罐油漆可刷的面积（单位：平方英尺）
int paint(void)
{
    int sq_feet;
    int cans;
    printf("Enter number of square feet to be painted:\n");
    while (scanf("%d", &sq_feet) == 1)
    {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
        printf("Enter next value (q to quit):\n");
    }
    return 0;
}

/* skippart.c -- 使用 continue 跳过部分循环 */
int skippart(void)
{
    const float MIN = 0.0f;
    const float MAX = 100.0f;
    float score;
    float total;
    int n = 0;
    float min = MAX;
    float max = MIN;
    printf("Enter the first score (q to quit):");
    while (scanf("%f", &score) == 1)
    {
        if (score < MIN || score > MAX) {
            printf("%0.1f is an invalid value. Try again: ", score);
            continue;    // 跳转至 while 循环的测试条件
        }
        printf("Accepting %0.1f:\n", score);
        min = (score < min) ? score : min;
        max = (score > max) ? score : max;
        total += score;
        n++;
        printf("Enter next score (q to quit):");
    }
    if (n > 0)
    {
        printf("Average of %d scores is %0.1f.\n", n, total / n);
        printf("Low = %0.1f, high = %0.1f\n", min, max);
    }
    else
    {
        printf("No valid scores were entered.\n");
    }
    return 0;
}

/* break.c -- 使用 break 退出循环 */
int break_(void)
{
    float length, width;
    printf("Enter the length of the rectangle:\n");
    while (scanf("%f", &length) == 1)
    {
        printf("Length = %0.2f:\n", length);
        printf("Enter its width:\n");
        if (scanf("%f", &width) != 1)
            break;
        printf("Width = %0.2f:\n", width);
        printf("Area = %0.2f:\n", length * width);
        printf("Enter the length of the rectangle:\n");
    }
    printf("Done.\n");
    return 0;
}

/* animals.c -- 使用 switch 语句 */
#include <ctype.h>
int animals(void)
{
    char ch;
    printf("Give me a letter of the alphabet, and I will give ");
    printf("an animal name\nbeginning with that letter.\n");
    printf("Please type in a letter, type # to end my act.\n");
    while ((ch = getchar()) != '#')
    {
        if ('\n' == ch)
            continue;
        if (islower(ch))    /* 只接受小写字母 */
        {
            switch (ch)
            {
            case 'a':
                printf("argali, a wild sheep of Asia\n");
                break;

            case 'b':
                printf("babirusa, a wild pig of Malay\n");
                break;

            case 'c':
                printf("coati, racoonlike mammal\n");
                break;

            case 'd':
                printf("desman, aquatic, molelike critter\n");
                break;

            case 'e':
                printf("echidna, the spiny anteater\n");
                break;

            case 'f':
                printf("fisher, brownish marten\n");
                break;

            default:
                printf("That's stumper!\n");
            }    /* switch 结束 */
        }
        else
        {
            printf("I recognize only lowercase letters.\n");
        }
        while (getchar() != '\n') {
            continue;    /* 跳过输入行的剩余部分 */
        }
        printf("Please type another letter or a #.\n");
    }
    printf("Bye!\n");
    return 0;
}

// vowels.c -- 使用多重标签
int vowels(void)
{
    char ch;
    int a_ct, e_ct, i_ct, o_ct, u_ct;
    a_ct = e_ct = i_ct = o_ct = u_ct = 0;
    printf("Enter some text;enter # to quit.\n");
    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            a_ct++;
            break;
            
        case 'e':
        case 'E':
            e_ct++;
            break;

        case 'i':
        case 'I':
            i_ct++;
            break;

        case 'o':
        case 'O':
            o_ct++;
            break;

        case 'u':
        case 'U':
            u_ct++;
            break;
            
        default:
            break;
        }    // switch 结束
    }
    printf("number of vowels:     A    E    I    O    U\n");
    printf("                   %4d %4d %4d %4d %4d", a_ct, e_ct, i_ct, o_ct, u_ct);
    return 0;
}


int main(int argc, const char * argv[]) {
    
//    colddays();
//    cypher1();
//    cypher2();
//    electric();
//    divisors();
//    chcount();
//    wordcnt();
//    paint();
//    skippart();
//    break_();
//    animals();
    vowels();
    
    return 0;
}
