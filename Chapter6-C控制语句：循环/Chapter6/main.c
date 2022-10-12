//
//  main.c
//  Chapter6
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>

/* summing.c -- 根据用户键入的整数求和 */
int summing(void)
{
    long num;
    long sum = 0L;    /* 把 sum 初始化为 0 */
    int status;
    printf("Please enter a integer to be summed ");
    printf("q to quit): ");
    status = scanf("%ld", &num);
    while (status == 1) /* == 的意思是“等于” */
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integrs sum to %ld.\n", sum);
    return 0;
}

// when.c -- 何时退出循环
int when(void)
{
    int n = 5;
    while (n < 7)
    {
        printf("n = %d\n", n);
        n++;
        printf("Now n = %d\n", n);
    }
    printf("The loop has finished.\n");
    return 0;
}

/* while1.c -- 注意花括号的使用 */
/* 糟糕的代码创建了一个无限循环 */
int while1(void)
{
    int n = 0;
    while (n < 3)
        printf("n is %d\n", n);
        n++;
    printf("That's all this program does\n");
    return 0;
}

/* while2.c -- 注意分号的位置 */
int while2(void)
{
    int n = 0;
    while (n++ < 3);
        printf("n is %d\n", n);
    printf("That's all this program does.\n");
    return 0;
}

// cmpflt.c -- 浮点数比较
#include <math.h>
int cmpflt(void)
{
    const double ANSWER = 3.14159;
    double response;
    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.0001)
    {
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");
    return 0;
}

/* t_and_f.c -- C 中的真和假的值 */
int t_and_f(void)
{
    int true_val, false_val;
    true_val = (10 > 2);    // 关系为真的值
    false_val = (10 == 2);    // 关系为假的值
    printf("true = %d; false = %d\n", true_val, false_val);
    return 0;
}

// truth.c -- 哪些值为真
int truth(void)
{
    int n = 3;
    while (n)
        printf("%2d is true\n", n--);
    printf("%2d is false\n", n);
    n = -3;
    while (n)
        printf("%2d is true\n", n++);
    printf("%2d is false\n", n);
    return 0;
}

// trouble.c -- 误用 = 会导致无限循环
int trouble(void)
{
    long num;
    long sum = 0L;
    int status;
    printf("Please enter an integer to be summed ");
    printf("q to quit): ");
    status = scanf("%ld", &num);
    while (status = 1)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}

// boolean.c -- 使用 _Bool 类型的变量 variable
int boolean(void)
{
    long num;
    long sum = 0L;
    _Bool input_is_good;
    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    input_is_good = (scanf("%ld", &num) == 1);
    while (input_is_good)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        input_is_good = (scanf("%ld", &num) == 1);
    }
    printf("Those integers sum to %ld.\n", sum);
    return 0;
}

// sweetie1.c -- 一个计数循环
int sweetie1(void)
{
    const int NUMBER = 22;
    int count = 1;    // 初始化
    while (count <= NUMBER) // 测试
    {
        printf("Be my Valentine!\n");    // 行为
        count++;    // 更新计数
    }
    return 0;
}

// sweetie2.c -- 使用 for 循环的计数循环
int sweetie2(void)
{
    const int NUMBER = 22;
    int count;
    for (count = 1; count <= NUMBER; count++)
    {
        printf("Be my Valentine!\n");
    }
    return 0;
}

/* for_cube.c -- 使用 for 循环创建一个立方表 */
int for_cube(void)
{
    int num;
    printf("    n    n cubed\n");
    for (num = 1; num <= 6; num++)
        printf("%5d %10d\n", num, num * num * num);
    return 0;
}

// postage.c -- 一类邮资
int postage(void)
{
    const int FIRST_OZ = 46;    // 2013 邮资
    const int NEXT_OZ = 20;    // 2013 邮资
    int ounces, cost;
    printf("  ounces     cost\n");
    for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
    {
        printf("%8d    $%4.2f\n", ounces, cost / 100.0);
    }
    return 0;
}

/* zeno.c -- 求序列的和 */
int zeno(void)
{
    int t_ct;    // 项计数
    double time, power_of_2;
    int limit;
    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);
    for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
    {
        time += 1.0 / power_of_2;
        printf("time = %f when terms = %d.\n", time, t_ct);
    }
    return 0;
}

/* do_while.c -- 出口条件循环 */
int do_while(void)
{
    const int secret_code = 13;
    int code_entered;
    do
    {
        printf("To enter the triskaidekaphobia therapy club,\n");
        printf("please enter the secret code number: ");
        scanf("%d", &code_entered);
    } while (code_entered != secret_code);
    printf("Conratulations! You are cured!\n");
    return 0;
}

/* entry.c -- 出口条件循环 */
int entry(void)
{
    const int secret_code = 13;
    int code_entered;
    printf("To enter the triskaidekaphobia therapy club,\n");
    printf("please enter the secret code number: ");
    scanf("%d", &code_entered);
    while (code_entered != secret_code)
    {
        printf("To enter the triskaidekaphobia therapy club,\n");
        printf("please enter the secret code number: ");
        scanf("%d", &code_entered);
    }
    printf("Congratulations! You are cured!\n");
    return 0;
}

/* rows1.c -- 使用嵌套循环 */
#define ROWS 6
#define CHARS 10
int rows1(void)
{
    int row;
    char ch;
    for (row = 0; row < ROWS; row++)
    {
        for (ch = 'A'; ch < ('A' + CHARS); ch++)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}

// rows2.c -- 依赖外部循环的嵌套循环
int rows2(void)
{
    const int ROWS2 = 6;
    const int CHARS2 = 6;
    int row;
    char ch;
    for (row = 0; row < ROWS2; row++)
    {
        for (ch = ('A' + row); ch < ('A' + CHARS2); ch++)
        {
            printf("%c|", ch);
        }
        printf("\n");
    }
    return 0;
}

// scores_in.c -- 使用循环处理数组
#define SIZE 10
#define PAR 72
int scores_in(void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;
    printf("Enter %d golf scores:\n", SIZE);
    for (index = 0; index < SIZE; index++)
    {
        scanf("%d", &score[index]);    // 读取 10 个分数
    }
    printf("The scores read in are as follows:\n");
    for (index = 0; index < SIZE; index++)
    {
        printf("%5d", score[index]);    // 验证输入
    }
    printf("\n");
    for (index = 0; index < SIZE; index++)
    {
        sum += score[index];    // 求总分
    }
    average = (float)sum / SIZE;    // 求平均分
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);
    return 0;
}

// power.c -- 计算数的整数幂
double power2(double n, int p)    // 函数定义
{
    double pow = 1;
    int i;
    for (i = 1; i <= p; i++)
    {
        pow *= n;
    }
    return pow;    // 返回 pow 的值
}

int power(void)
{
    double x, xpow;
    int exp;
    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");
    while (scanf("%lf%d", &x, &exp) == 2)
    {
        xpow = power2(x, exp);    // 函数调用
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip -- bye!\n");
    return 0;
}




int main(int argc, const char * argv[]) {
 
//    summing();
//    when();
//    while1();
//    while2();
//    cmpflt();
//    t_and_f();
//    truth();
//    trouble();
//    boolean();
//    sweetie1();
//    sweetie2();
//    for_cube();
//    postage();
//    zeno();
//    do_while();
//    entry();
//    rows1();
//    rows2();
//    scores_in();
    power();
    
    return 0;
}
