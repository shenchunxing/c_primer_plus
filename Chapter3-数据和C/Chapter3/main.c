//
//  main.c
//  Chapter3
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>
#include <inttypes.h>    // 支持可移植类型

int platinum(void)
{
    float weight;    /* 你的体重 */
    float value;    /* 相等种类的白金价值 */
    printf("Are you worth your weight in platinum?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds: ");
    /* 获取用户的输入 */
    scanf("%f", &weight);
    /* 假设白金的价格是每盎司 $1700 */
    /* 14.5833 用于把英镑常衡盎司转换为金衡盎司 */
    value = 1700.0 * weight * 14.5833;
    printf("Your weight in platinum is worth $%.2f.\n", value);
    printf("You are easily worth that! If platinum prices drop,\n");
    printf("eat more to maintain your value.\n");
    return 0;
}

int print1(void)
{
    int ten = 10;
    int two = 2;
    printf("Doing it right: ");
    printf("%d minus %d is %d\n", ten, 2, ten - two);
    printf("Doing it wrong: ");
    printf("%d minus %dis %d\n", ten);    // 遗漏 2 个参数
    return 0;
}

int bases(void)
{
    int x = 100;
    printf("10进制 = %d; 8进制 = %o; 16进制 = %x\n", x, x, x);//不显示前缀
    printf("10进制 = %d; 8进制 = %#o; 16进制 = %#x\n", x, x, x);//显示前缀
    return 0;
}

int tobig(void) //溢出
{
    int i = 2147483647;//有符号
    unsigned int j = 4294967295;//无符号
    printf("%d %d %d\n", i, i + 1, i + 2);//2147483647  -2147483648 -2147483647
    printf("%u %u %u\n", j, j + 1, j + 2);//4294967295 0 1
    return 0;
}

int print2(void)
{
    unsigned int un = 3000000000;    /* int 为 32 位和 short 为 16 位的系统 */
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    printf("un = %u and not %d\n", un, un);//有符号和无符号的区别，%d是有符号的。%u是无符号的
    printf("end= %hd an %d\n", end, end);//short自动转成int ，hd和d都可以正常显示200
    printf("big = %ld and not %hd\n", big, big);//ld显示全值，hd是截断后16位得到的值
    printf("verybig = %lld and not %ld\n", verybig, verybig);//lld显示全值，ld只显示最后的32位得到的值
    return 0;
}

int charcode(void)
{
    char ch;
    printf("Please enter a character.\n");
    scanf("%c", &ch);    /* 用户输入字符 */
    printf("The code for %c is %d.\n", ch, ch);//转成ASSIC码
    return 0;
}

int altnames(void)
{
    int32_t me32;    // me32 是一个 32 为有符号整型变量
    me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" from inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32); //PRId32 = "d"
    return 0;
}

int showf_pt(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;
    printf("%f can be written %e\n", aboat, aboat);//32000.000000 can be written 3.200000e+04
    // 下一行要求编译器支持 C99 或其中的相关特性
    printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);//And it's 0x1.f4p+14 in hexadecimal, powers of 2 notation
    printf("%f can be written %e\n", abet, abet);//2140000000.000000 can be written 2.140000e+09
    printf("%Lf can be written %Le\n", dip, dip);//0.000053 can be written 5.320000e-05
    return 0;
}

int floaterr(void)
{
    float a, b;
    b = 2.0e20 + 1.0;
    a = b - 2.0e20;
    printf("%f \n", a);//4008175468544.000000 ,float只能表示6-7位有效数字
    
    float c, d;
    d = 2.0e4 + 1.0;
    c = d - 2.0e4;
    printf("%f \n", c);//1.000000
    
    return 0;
}


int typesize(void)//打印类型大小
{
    /* C99 为类型大小提供 %zd 转换说明 */
    //Type int has a size of 4 bytes.
//    Type char has a size of 1 bytes.
//    Type long has a size of 8 bytes.
//    Type long long has a size of 8 bytes.
//    Type double has a size of 8 bytes.
//    Type long double has a size of 16 bytes.
    printf("Type int has a size of %zd bytes.\n", sizeof(int));
    printf("Type char has a size of %zd bytes.\n", sizeof(char));
    printf("Type long has a size of %zd bytes.\n", sizeof(long));
    printf("Type long long has a size of %zd bytes.\n",
        sizeof(long long));//在32位下，long类型只保留4个字节，而long long 有8个字节.64位下都是8个字节
    printf("Type double has a size of %zd bytes.\n",
        sizeof(double));
    printf("Type long double has a size of %zd bytes.\n",
        sizeof(long double));
    return 0;
}

/* badcount.c -- 参数错误的情况 */
int badcount(void)
{
    int n = 4;
    int m = 5;
    float f = 7.0f;
    float g = 8.0f;
    printf("%d\n", n, m);    /* 参数太多 */
    printf("%d %d %d\n", n);    /* 参数太少 */
    printf("%d %d\n", f, g);    /* 值的类型不匹配，float不会转成%d的int值 */
    return 0;
}

/* escape.c -- 使用转义序列 */
int escape(void) {
    float salary;
    printf("\aEnter your desired monthly salary:");
    printf(" $______\b\b\b\b\b\b\b");
    scanf("%f",&salary);
    printf("\n\t$%.2f a month is $%.2f a year.",salary,
           salary * 12.0);
    printf("\rGee!\n");
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    platinum();
//    print1();
//    bases();
//    tobig();
//    print2();
//    charcode();
//    altnames();
//    showf_pt();
//    floaterr();
//    typesize();
//    badcount();
    escape();
    return 0;
}




