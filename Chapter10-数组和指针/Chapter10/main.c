//
//  main.c
//  Chapter10
//
//  Created by 沈春兴 on 2022/10/10.
//

#include <stdio.h>
#include "array2d.h"
#include "vararr2d.h"
#include "flc.h"
#define MONTHS 12
/* day_mon1.c -- 打印每个月天数 */
void day_mon1(void) {
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    
    for (index = 0; index < MONTHS; index++)
        printf("Month %d has %2d days.\n", index +1,
               days[index]);
}

#define SIZE 4
/* no_data.c -- 为初始化数组 */
void no_data(void)
{
    int no_data[SIZE];  /* uninitialized array */
    int i;
    
    printf("%2s%14s\n",
           "i", "no_data[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, no_data[i]);
}
/* some_data.c -- 部分初始化数组 */
void some_data(void) {
    int some_data[SIZE] = {1492, 1066};
    int i;
    
    printf("%2s%14s\n",
           "i", "some_data[i]");
    for (i = 0; i < SIZE; i++)
        printf("%2d%14d\n", i, some_data[i]);
}

/* day_mon2.c -- 让编译器计算元素个数 */
void day_mon2(void) {
    const int days[] = {31,28,31,30,31,30,31,31,30,31};
    int index;
    
    for (index = 0; index < sizeof days / sizeof days[0]; index++)
        printf("Month %2d has %d days.\n", index +1,
               days[index]);
}

// designate.c -- 使用指定初始化器
void designated(void) {
    int days[MONTHS] = {31,28, [4] = 31,30,31, [1] = 29};
    int i;
    
    for (i = 0; i < MONTHS; i++)
        printf("%2d  %d\n", i + 1, days[i]);
}

// bounds.c -- 数组下标越界
#include <stdio.h>
int bounds(void)
{
    int value1 = 44;
    int arr[SIZE];
    int value2 = 88;
    int i;
    
    printf("value1 = %d, value2 = %d\n", value1, value2);
    for (i = -1; i <= SIZE; i++) //i < SIZE
        arr[i] = 2 * i + 1;
    
    for (i = -1; i < 7; i++)
        printf("%2d  %d\n", i , arr[i]);
    printf("value1 = %d, value2 = %d\n", value1, value2);
    
    printf("address of arr[-1]: %p\n", &arr[-1]);
    printf("address of arr[4]:  %p\n", &arr[4]);
    printf("address of value1:  %p\n", &value1);
    printf("address of value2:  %p\n", &value2);
   
    return 0;
}

/* rain.c  -- 计算年总数、年平均值和月数年降雨量数据的平均值 */
#include <stdio.h>
#define YEARS   5    // number of years of data
int rain(void)
{
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    int year, month;
    float subtot, total;
    
    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {             // for each year, sum rainfall for each month
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
           total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");
    
    for (month = 0; month < MONTHS; month++)
    {             // for each month, sum rainfall over years
        for (year = 0, subtot =0; year < YEARS; year++)
            subtot += rain[year][month];
        printf("%4.1f ", subtot/YEARS);
    }
    printf("\n");
    
    return 0;
}

// pnt_add.c -- 指针地址
#include <stdio.h>
int pnt_add(void)
{
    short dates [SIZE];
    short * pti; //指针本身占用8个字节，指向的元素short类型只占用2个字节
    short index;
    double bills[SIZE];
    double * ptf;//占用8个字节
    
    pti = dates;    // assign address of array to pointer
    ptf = bills;
    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index ++)
        printf("pointers + %d: %10p %10p\n",
               index, pti + index, ptf + index);
    
    printf("%lu", sizeof(int *));
    printf("%lu", sizeof(short *));
    printf("%lu", sizeof(long *));
    printf("%lu", sizeof(float *));
    printf("%lu", sizeof(double *));
    printf("%lu", sizeof(long long *));
    return 0;
}

/* day_mon3.c -- 使用指针 */
#include <stdio.h>
int day_mon3(void)
{
    int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int index;
    
    for (index = 0; index < MONTHS; index++)
        printf("Month %2d has %d days.\n", index +1,
               *(days + index));   // same as days[index]
    
    return 0;
}

// sum_arr1.c -- 数组元素之和
// use %u or %lu if %zd doesn't work
#include <stdio.h>
#define SIZE2 10
int sum(int ar[], int n);
int sum_arr1(void)
{
    int marbles[SIZE2] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    
    answer = sum(marbles, SIZE2);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",
           sizeof marbles);//数组大小 4 * 10 = 40
    
    return 0;
}

int sum(int ar[], int n)     // how big an array?
{
    int i;
    int total = 0;
    
    for( i = 0; i < n; i++)
        total += ar[i];
    printf("The size of ar is %zd bytes.\n", sizeof ar); //传进来的实际是指针，打印的是指针的大小8字节
    
    return total;
}

/* sum_arr2.c -- 数组元素之和 */
#include <stdio.h>
int sump(int * start, int * end);
int sum_arr2(void)
{
    int marbles[SIZE2] = {20,10,5,39,4,16,19,26,31,20};
    long answer;
    
    answer = sump(marbles, marbles + SIZE2);
    printf("The total number of marbles is %ld.\n", answer);
    
    return 0;
}

/* 使用指针算法   */
int sump(int * start, int * end) //指针的起始位置和结束位置
{
    int total = 0;
    
    while (start < end)
    {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }
    
    return total;
}

/* order.c -- 指针运算中的优先级 */
#include <stdio.h>
int data[2] = {100, 200};
int moredata[2] = {300, 400};
int order(void)
{
    int * p1, * p2, * p3;
    
    p1 = p2 = data;
    p3 = moredata;
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",
           *p1     ,   *p2     ,     *p3);//  *p1 = 100,   *p2 = 100,     *p3 = 300
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n",
           *p1++     , *++p2     , (*p3)++); //*p1++ = 100, *++p2 = 200, (*p3)++ = 300
    printf("  *p1 = %d,   *p2 = %d,     *p3 = %d\n",
           *p1     ,   *p2     ,     *p3); //  *p1 = 200,   *p2 = 200,     *p3 = 301
    
    return 0;
}


// ptr_ops.c -- 指针操作
#include <stdio.h>
int ptr_ops(void)
{
    int urn[5] = {100,200,300,400,500};
    int * ptr1, * ptr2, *ptr3;
    
    ptr1 = urn;         // assign an address to a pointer
    ptr2 = &urn[2];     // ditto
    // dereference a pointer and take
    // the address of a pointer
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
           ptr1, *ptr1, &ptr1);//ptr1 = 0x3040cb290, *ptr1 =100, &ptr1 = 0x3040cb288
    
    // pointer addition
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr4 + 3) = %d\n",
           ptr1 + 4, *(ptr1 + 3));//ptr1 + 4 = 0x3040cb2a0, *(ptr4 + 3) = 400
    ptr1++;            // increment a pointer
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
           ptr1, *ptr1, &ptr1);//ptr1 = 0x3040cb294, *ptr1 =200, &ptr1 = 0x3040cb288
    ptr2--;            // decrement a pointer
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
           ptr2, *ptr2, &ptr2);//ptr2 = 0x3040cb294, *ptr2 = 200, &ptr2 = 0x3040cb280
    --ptr1;            // restore to original value
    ++ptr2;            // restore to original value
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);//ptr1 = 0x3040cb290, ptr2 = 0x3040cb298
    // subtract one pointer from another
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",
           ptr2, ptr1, ptr2 - ptr1); //ptr2 = 0x3040cb298, ptr1 = 0x3040cb290, ptr2 - ptr1 = 2
    // subtract an integer from a pointer
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n",
           ptr3,  ptr3 - 2);//ptr3 = 0x3040cb2a0, ptr3 - 2 = 0x3040cb298
    
    return 0;
}

/* arf.c -- 处理数组的函数 */
#include <stdio.h>
#define SIZE3 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
int arf(void)
{
    double dip[SIZE3] = {20.0, 17.66, 8.2, 15.3, 22.22};
    
    printf("The original dip array:\n");
    show_array(dip, SIZE3);
    mult_array(dip, SIZE3, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(dip, SIZE3);
    
    return 0;
}

/* 显示数组的内容 */
void show_array(const double ar[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    putchar('\n');
}

/* 把数组的每个元素都乘以相同的值 */
void mult_array(double ar[], int n, double mult)
{
    int i;
    
    for (i = 0; i < n; i++)
        ar[i] *= mult;
}

/* zippo1.c --  zippo相关信息 */
#include <stdio.h>
int zippo1(void)
{
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
    
    printf("   zippo = %p,    zippo + 1 = %p\n",
           zippo,         zippo + 1);//zippo = 0x3040cb280,    zippo + 1 = 0x3040cb288
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
           zippo[0],      zippo[0] + 1);//zippo[0] = 0x3040cb280, zippo[0] + 1 = 0x3040cb284({2,4}中的4地址)
    printf("  *zippo = %p,   *zippo + 1 = %p\n",
           *zippo,        *zippo + 1);// *zippo = 0x3040cb280,   *zippo + 1 = 0x3040cb284{2,4}中的4地址)
    printf("zippo[0][0] = %d\n", zippo[0][0]);//zippo[0][0] = 2
    printf("  *zippo[0] = %d\n", *zippo[0]);//  *zippo[0] = 2
    printf("    **zippo = %d\n", **zippo);//    **zippo = 2
    printf("      zippo[2][1] = %d\n", zippo[2][1]);//      zippo[2][1] = 3
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));//*(*(zippo+2) + 1) = 3
    
    return 0;
}

/* zippo2.c --  通过指针获取zippo的信息 */
#include <stdio.h>
int zippo2(void)
{
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
    int (*pz)[2];//定义函数指针
    pz = zippo;
    
    printf("   pz = %p,    pz + 1 = %p\n",
           pz,         pz + 1);//   pz = 0x3040cb280,    pz + 1 = 0x3040cb288
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
           pz[0],      pz[0] + 1);//pz[0] = 0x3040cb280, pz[0] + 1 = 0x3040cb284
    printf("  *pz = %p,   *pz + 1 = %p\n",
           *pz,        *pz + 1);//  *pz = 0x3040cb280,   *pz + 1 = 0x3040cb284
    printf("pz[0][0] = %d\n", pz[0][0]);//pz[0][0] = 2
    printf("  *pz[0] = %d\n", *pz[0]);//  *pz[0] = 2
    printf("    **pz = %d\n", **pz);//    **pz = 2
    printf("      pz[2][1] = %d\n", pz[2][1]);//      pz[2][1] = 3
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));//*(*(pz+2) + 1) = 3
    
    return 0;
}

int main(int argc, const char * argv[]) {

//    day_mon1();
//    no_data();
//    some_data();
//    day_mon2();
//    designated();
//    bounds();
//    rain();
//    pnt_add();
//    day_mon3();
//    sum_arr1();
//    sum_arr2();
//    order();
//    ptr_ops();
//    arf();
//    zippo1();
//    zippo2();
    
//    array2d();
//    vararr2d();
    flc();
    return 0;
}
