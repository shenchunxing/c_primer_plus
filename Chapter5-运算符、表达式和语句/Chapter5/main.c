//
//  main.c
//  Chapter5
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>

/* shoes1.c -- 把鞋码转换成英寸 */
#define ADJUST 7.31    // 字符常量
int shoes1(void)
{
    const double SCALE = 0.333;    // const 变量
    double shoe, foot;
    shoe = 9.0;
    foot = SCALE * shoe + ADJUST;
    printf("Shoe size (men's) foot length\n");
    printf("%10.1f %15.2f inches\n", shoe, foot);
    return 0;
}

/* shoes2.c -- 计算多个不同鞋码对应的脚长 */
int shoes2(void)
{
    const double SCALE = 0.333;    // const 变量
    double shoe, foot;
    printf("Shoe size (men's) foot length\n");
    shoe = 3.0;
    while (shoe < 18.5)        /* while 循环开始 */
    {                        /* 块开始 */
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f inches\n", shoe, foot);
        shoe = shoe + 1.0;
    }                        /* 块结束 */
    printf("If the shoe fits, wear it.\n");
    return 0;
}

/* golf.c -- 高尔夫锦标赛记分卡 */
int golf(void)
{
    int jane, tarzan, cheeta;
    cheeta = tarzan = jane = 68;
    printf("                  cheeta    tarzan      jane\n");
    printf("First round score   %4d  %8d  %8d\n", cheeta, tarzan, jane);
    return 0;
}

/* squares.c -- 计算 1 ~ 20 的平方 */
int squares(void)
{
    int num = 1;
    while (num < 21)
    {
        printf("%4d %6d\n", num, num * num);
        num = num + 1;
    }
    return 0;
}

/* wheat.c -- 指数增长 */
#define SQUARES 64    // 棋盘中的方格数
int wheat(void)
{
    const double CROP = 2E16;    // 世界小麦年产谷粒数
    double current, total;
    int count = 1;
    printf("square       grains         total     ");
    printf("fraction of   \n");
    printf("              added        grains    ");
    printf("world  total\n");
    total = current = 1.0;    /* 从 1 颗谷粒开始 */
    printf("%4d  %13.2e  %12.2e  %12.2e\n", count, current, total, total / CROP);
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;    /* 下一个方格谷粒翻倍 */
        total = total + current;    /* 更新总数 */
        printf("%4d  %13.2e  %12.2e  %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");
    return 0;
}

/* divide.c -- 演示除法 */
int divide(void)
{
    printf("integer division: 5/4 is %d\n", 5 / 4);
    printf("integer division: 6/3 is %d\n", 6 / 3);
    printf("integer division: 7/4 is %d\n", 7 / 4);
    printf("floating division: 7./4. is %1.2f\n", 7. / 4.);
    printf("mixed division: 7./4 is %1.2f\n", 7. / 4);
    return 0;
}

/* rules.c -- 优先级测试 */
int rules(void)
{
    int top, score;
    top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
    printf("top = %d, score = %d\n", top, score);
    return 0;
}

// sizeof.c -- 使用 sizeof 运算符
// 使用 C99 新增的 %zd 转换说明 -- 如果编译器不支持 %zd，请将其改成 %u 或 %lu
int sizeof_(void)
{
    int n = 0;
    size_t intsize;//size_t 无符号整数类型
    intsize = sizeof(int);
    printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof n, intsize);
    return 0;
}

// min_sec.c -- 把秒数转换成分和秒
#define SEC_PER_MIN 60    // 1 分钟 60 秒
int min_sec(void)
{
    int sec, min, left;
    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d", &sec);    // 读取秒数
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;    // 截断分钟数
        left = sec % SEC_PER_MIN;    // 剩下的秒数
        printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d", &sec);
    }
    printf("Done!\n");
    return 0;
}

/* add_one.c -- 递增：前缀和后缀 */
int add_one(void)
{
    int ultra = 0, super = 0;
    while (super < 5)
    {
        super++;
        ++ultra;
        printf("super = %d, ultra = %d\n", super, ultra);
    }
    return 0;
}

/* post_pre.c -- 前缀和后缀 */
int post_pre(void)
{
    int a = 1, b = 1;
    int a_post, pre_b;
    a_post = a++;    // 后缀递增
    pre_b = ++b;    // 前缀递增
    printf("a   a_post      b      pre_b \n");
    printf("%1d    %5d  %5d      %5d\n", a, a_post, b, pre_b);
    return 0;
}

/* bottles.c -- 演示了计算机可以是位出色的填词家 */
#define MAX 100
int bottles(void)
{
    int count = MAX + 1;
    while (--count > 0)
    {
        printf("%d bottles of spring water on the wall, "
            "%d bottles of spring water!\n", count, count);
        printf("Take one down and pass it around,\n");
        printf("%d bottles of spring water!\n\n", count - 1);
    }
    return 0;
}

/* addemup.c -- 几种常见的语句 */
int addemup(void)    /* 计算前 20 个整数的和 */
{
    int count, sum;    /* 声明 */
    count = 0;    /* 表达式语句 */
    sum = 0;    /* 表达式语句 */
    while (count++ < 20)    /* 迭代语句 */
    {
        sum = sum + count;
    }
    printf("sum = %d\n", sum);    /* 表达式语句 */
    return 0;    /* 跳转语句 */
}

/* convert.c -- 自动类型转换 */
int convert(void)
{
    char ch;
    int i;
    float fl;
    fl = i = ch = 'C';    /* 第9行 */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);    /* 第 10 行 */
    ch = ch + 1;    /* 第 11 行 */
    i = fl + 2 * ch;    /* 第 12 行 */
    fl = 2.0 * ch + i;    /* 第 13 行 */
    printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);    /* 第 14 行 */
    ch = 1107;    /* 第 15 行 */
    printf("Now ch = %c\n", ch);    /* 第 16 行 */
    ch = 80.89;    /* 第 17 行 */
    printf("Now ch = %c\n", ch);    /* 第 18 行 */
    return 0;
}

/* pound.c -- 定义一个带一个参数的函数 */
void pound(int n)    // ANSI 风格函数头
{
    while (n-- > 0) {
        printf("#");
    }
    printf("\n");
}

int pound2(void)
{
    int times = 5;
    char ch = '!';    // ASCII 码是 33
    float f = 6.0f;
    pound(times);    // int 类型的参数
    pound(ch);        // 和 pound((int)ch); 相同
    pound(f);        // 和 pound((int)f); 相同
    return 0;
}

// running.c -- A useful program for runners
const int S_PER_M = 60;    // 1 分钟的秒数
const int S_PER_H = 3600;    // 1 小时的秒数
const double M_PER_K = 0.62137;    // 1 公里的英里数
int running(void)
{
    double distk, distm;    // 跑过的距离（分别以公里和英里为单位）
    double rate;    // 平均速度（以英里/小时为单位）
    int min, sec;    // 跑步用时（以分钟和秒为单位）
    int time;        // 跑步用时（以秒为单位）；
    double mtime;    // 跑 1 英里需要的时间，以秒为单位
    int mmin, msec;    // 跑 1 英里需要的时间，以分钟和秒为单位
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%lf", &distk);    // %lf 表示读取一个 double 类型的值
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);
    time = S_PER_M * min + sec;    // 把时间转换成秒
    distm = M_PER_K * distk;    // 把公里转换成英里
    rate = distm / time * S_PER_H;    // 英里 / 秒 x 秒 / 小时 = 英里 / 小时
    mtime = (double)time / distm;    // 时间 / 距离 = 跑 1 英里所用的时间
    mmin = (int)mtime / S_PER_M;    // 求出分钟数
    msec = (int)mtime % S_PER_M;    // 求出剩余的秒数
    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
    return 0;
}

int main(int argc, const char * argv[]) {
   
//    shoes1();
//    shoes2();
//    golf();
//    squares();
//    wheat();
//    divide();
//    rules();
//    sizeof_();
//    min_sec();
//    add_one();
//    post_pre();
//    bottles();
//    addemup();
//    convert();
//    pound2();
    running();
    return 0;
}
