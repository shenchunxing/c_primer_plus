//
//  main.c
//  Chapter4
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>
#include <string.h>    // 提供 strlen() 函数的原型
#include <limits.h>    // 整型限制
#include <float.h>    // 浮点型限制

#define DENSITY 62.4    // 人体密度（单位：磅/立方英尺）

// talkback.c -- 演示与用户交互
int talkback()
{
    float weight, volume;
    int size, letters;
    char name[40];    // name 是一个可容纳 40 个字符的数组
    printf("Hi! What's your first name?\n");
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);
    return 0;
}

#define PRAISE "You are an extraordinary being."
/* praise1.c -- 使用不同类型的字符串 */
int praise1(void)
{
    char name[40];
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    return 0;
}

/* praise2.c */
// 如果编译器不识别 %zd，尝试换成 %u 或 %lu。
int praise2(void)
{
    char name[40];//申请了40个字符的空间大小
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n",
        strlen(name), sizeof name);//strlen：字符长度 sizeof：对象大小是40，但是只有一部分存储字符。
    printf("The phrase of praise has %zd letters ",
        strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);
    return 0;
}

#define PI 3.14159
/* pizza.c -- 在比萨饼程序中使用已定义的常量 */
int pizza(void)
{
    float area, circum, radius;
    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza parameters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);
    return 0;
}

// defines.c -- 使用 limit.h 和 float 头文件中定义的明示常量
int defines(void)
{
    printf("Some number limits for this system:\n");
    printf("Biggest int: %d\n", INT_MAX);
    printf("Smallest long long: %lld\n", LLONG_MIN);
    printf("One byte = %d bits on this system.\n", CHAR_BIT);
    printf("Largest double: %e\n", DBL_MAX);
    printf("Smallest normal float: %e\n", FLT_MIN);
    printf("float precision = %d digits\n", FLT_DIG);
    printf("float epsilon = %e\n", FLT_EPSILON);
    return 0;
}

/* printout.c -- 使用转换说明 */
int printout(void)
{
    int number = 7;
    float pies = 12.75;
    int cost = 7800;
    printf("The %d contestants ate %f berry pies.\n", number, pies);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thou art too dear for my possessing,\n");
    printf("%c%d\n", '$', 2 * cost);
    return 0;
}

#define PAGES 959
/* width.c -- 字段宽度 */
int width(void)
{
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);
    return 0;
}

// floats.c -- 一些浮点型修饰符的组合
int floats(void)
{
    const double RENT = 3852.99;    // const 变量
    printf("*%f*\n", RENT);
    printf("*%e*\n", RENT);
    printf("*%4.2f*\n", RENT);
    printf("*%3.1f*\n", RENT);
    printf("*%10.3f*\n", RENT);
    printf("*%10.3E*\n", RENT);
    printf("*%+4.2f*\n", RENT);
    printf("*%010.2f*\n", RENT);
    return 0;
}

/* flags.c -- 演示一些格式标记 */
int flags(void)
{
    printf("%x %X %#x\n", 31, 31, 31);//1f 1F 0x1f
    printf("**%d**% d**% d**\n", 42, 42, 42);//**42** 42** 42**
    printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);//**    6**  006**00006**  006**
    return 0;
}

#define BLURB "Authentic imitation!"
/* stringf.c -- 字符串格式 */
int stringf(void)
{
    printf("[%2s]\n", BLURB);//虽然是2s，但是长度会被扩容到现实所有字符
    printf("[%24s]\n", BLURB);//长度24
    printf("[%24.5s]\n", BLURB);//.5表示只打印5个字符
    printf("[%-24.5s]\n", BLURB);//-表示左对齐
    return 0;
}

#define PAGES2 336
#define WORDS 65618
/* intconv.c -- 一些不匹配的整型转换 */
int intconv(void)
{
    short num = PAGES2;
    short mnum = -PAGES2;
    printf("num as short and unsigned short: %hd %hu\n", num, num);//num as short and unsigned short: 336 336
    printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);//-num as short and unsigned short: -336 65200,%hu是无符号，0-32767代表本身，超过部分表示负数.65535表示-1.
    printf("num as int and char: %d %c\n", num, num);//num as int and char: 336 P
    printf("WORDS as int, short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);//WORDS as int, short, and char: 65618 82 R   %hd只用最后16位也就是最后的2个字节，65618 % 65535 = 82
    return 0;
}

/* floatcnv.c -- 不匹配的浮点类型转换 */
int floatcnv(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 200000000;
    long n4 = 1234567890;
    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
    return 0;
}

/* prntval.c -- printf() 的返回值 */
int prntval(void)
{
    int bph2o = 212;
    int rv;
    rv = printf("%d F is water's boiling point.\n", bph2o);//返回打印字符的个数
    printf("The printf() function printed %d characters.\n", rv);
    return 0;
}

/* longstrg.c -- 打印较长的字符串 */
int longstrg(void)
{
    printf("Here's one way to print a");
    printf("long string. \n");
    printf("Here's another way to print a \
long string.\n");
    printf("Here's the newest way to print a "
        "long string.\n");    /* ANSI C */
    return 0;
}

// input.c -- 何时使用&
int input(void)
{
    int age;    // 变量
    float assets;    // 变量
    char pet[30];    // 字符数组，用于存储字符串
    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);    // 这里要使用 &
    scanf("%s", pet);    // 字符数组不使用 &
    printf("%d $%.2f %s\n", age, assets, pet);
    return 0;
}

/* varwid.c -- 使用变宽输出字段 */
int varwid(void)
{
    /**
     Enter a field width:
     6
     The number is :    256:
     Now enter a width and a precision:
     8 3
     Weight =  242.500
     Done!
     */
    unsigned width, precision;
    int number = 256;
    double weight = 242.5;
    printf("Enter a field width:\n");
    scanf("%d", &width);
    printf("The number is : %*d:\n", width, number);
    printf("Now enter a width and a precision:\n");
    scanf("%d %d", &width, &precision);
    printf("Weight = %*.*f\n", width, precision, weight);
    printf("Done!\n");
    return 0;
}

/* skiptwo.c -- 跳过输入中的前两个整数 */
int skiptwo(void)
{
    int n;
    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &n);
    printf("The last integer was %d\n", n);
    return 0;
}

int main(int argc, const char * argv[]) {
    
//    talkback();
//    praise1();
//    praise2();
//    pizza();
//    defines();
//    printout();
//    width();
//    floats();
//    flags();
//    stringf();
//    intconv();
//    floatcnv();
//    prntval();
//    longstrg();
//    input();
//    varwid();
    skiptwo();
    return 0;
}
