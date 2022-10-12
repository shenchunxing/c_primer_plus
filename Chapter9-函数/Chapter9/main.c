//
//  main.c
//  Chapter9
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>

/* lethead1.c */
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
void starbar(void)   /* define the function    */
{
    int count;
    
    for (count = 1; count <= WIDTH; count++)
        putchar('*');
    putchar('\n');
}
int lethead1(void)
{
    starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    starbar();       /* use the function       */
    
    return 0;
}

/* lethead2.c */
#include <string.h>            /* for strlen() */
#define SPACE ' '
void show_n_char(char ch, int num);

int lethead2(void)
{
    int spaces;
    
    show_n_char('*', WIDTH);   /* using constants as arguments */
    putchar('\n');
    show_n_char(SPACE, 12);    /* using constants as arguments */
    printf("%s\n", NAME);
    spaces = (WIDTH - strlen(ADDRESS)) / 2;
    /* Let the program calculate    */
    /* how many spaces to skip      */
    show_n_char(SPACE, spaces);/* use a variable as argument   */
    printf("%s\n", ADDRESS);
    show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);
    /* an expression as argument    */
    printf("%s\n", PLACE);
    show_n_char('*', WIDTH);
    putchar('\n');
    
    return 0;
}

/* show_n_char() definition */
void show_n_char(char ch, int num)
{
    int count;
    
    for (count = 1; count <= num; count++)
        putchar(ch);
}

/* lesser.c -- finds the lesser of two evils */
int imin(int, int);
int lesser(void)
{
    int evil1, evil2;
    
    printf("Enter a pair of integers (q to quit):\n");
    while (scanf("%d %d", &evil1, &evil2) == 2)
    {
        printf("The lesser of %d and %d is %d.\n",
               evil1, evil2, imin(evil1,evil2));
        printf("Enter a pair of integers (q to quit):\n");
    }
    printf("Bye.\n");
    
    return 0;
}

int imin(int n,int m)
{
    int min;
    
    if (n < m)
        min = n;
    else
        min = m;
    
    return min;
}

/* misuse.c -- uses a function incorrectly */
int imax();      /* old-style declaration */
int misuse(void)
{
    printf("The maximum of %d and %d is %d.\n",
           3, 5, imax(3));
    printf("The maximum of %d and %d is %d.\n",
           3, 5, imax(3.0, 5.0));
    return 0;
}

int imax(n, m)
int n, m;
{
    return (n > m ? n : m);
}

/* proto.c -- uses a function prototype */
int imax2(int, int);        /* prototype */
int proto(void)
{
    printf("The maximum of %d and %d is %d.\n",
           3, 5, imax2(3,5));
    printf("The maximum of %d and %d is %d.\n",
           3, 5, imax2(3.0, 5.0));
    return 0;
}

int imax2(int n, int m)
{
    return (n > m ? n : m);
}


/* recur.c -- recursion illustration */
void up_and_down(int);
int recur(void)
{
    up_and_down(1);
    return 0;
}

void up_and_down(int n)
{
    printf("Level %d: n location %p\n", n, &n); // 1
    if (n < 4)
        up_and_down(n+1);
    printf("LEVEL %d: n location %p\n", n, &n); // 2
    
}


// factor.c -- uses loops and recursion to calculate factorials
long fact(int n);
long rfact(int n);
int factor(void)
{
    int num;
    
    printf("This program calculates factorials.\n");
    printf("Enter a value in the range 0-12 (q to quit):\n");
    while (scanf("%d", &num) == 1)
    {
        if (num < 0)
            printf("No negative numbers, please.\n");
        else if (num > 12)
            printf("Keep input under 13.\n");
        else
        {
            printf("loop: %d factorial = %ld\n",
                   num, fact(num));
            printf("recursion: %d factorial = %ld\n",
                   num, rfact(num));
        }
        printf("Enter a value in the range 0-12 (q to quit):\n");
    }
    printf("Bye.\n");
    
    return 0;
}

//for循环
long fact(int n)     // loop-based function
{
    long ans;
    
    for (ans = 1; n > 1; n--)
        ans *= n;
    
    return ans;
}
//递归
long rfact(int n)    // recursive version
{
    long ans;
    
    if (n > 0)
        ans= n * rfact(n-1);
    else
        ans = 1;
    
    return ans;
}

/* binary.c -- prints integer in binary form */
void to_binary(unsigned long n);
int binary(void)
{
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    
    return 0;
}

void to_binary(unsigned long n)   /* recursive function */
{
    int r;
    
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
     putchar(r == 0 ? '0' : '1');
    
    return;
}

/* usehotel.c -- room rate program */
/* compile with  Listing 9.10      */
#include "hotel.h" /* defines constants, declares functions */
int usehotel(void)
{
    int nights;
    double hotel_rate;
    int code;
    
    while ((code = menu()) != QUIT)
    {
        switch(code)
        {
            case 1 : hotel_rate = HOTEL1;
                break;
            case 2 : hotel_rate = HOTEL2;
                break;
            case 3 : hotel_rate = HOTEL3;
                break;
            case 4 : hotel_rate = HOTEL4;
                break;
            default: hotel_rate = 0.0;
                printf("Oops!\n");
                break;
        }
        nights = getnights();
        showprice(hotel_rate, nights);
    }
    printf("Thank you and goodbye.\n");
    
    return 0;
}


/* loccheck.c  -- 查看变量被存储在何处  */
#include <stdio.h>
void mikado(int);                      /* declare function  */
int loccheck(void)
{
    int pooh = 2, bah = 5;             /* local to main()   */
    
    printf("In main(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",
           bah, &bah);
    mikado(pooh);
    
    return 0;
}

void mikado(int bah)                   /* define function   */
{
    int pooh = 10;                     /* local to mikado() */
    
    printf("In mikado(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",
           bah, &bah);
}

/* swap1.c -- 第一个版本的交换函数 */
void interchange(int u, int v); /* declare function */

int swap1(void)
{
    int x = 5, y = 10;
    
    printf("Originally x = %d and y = %d.\n", x , y);
    interchange(x, y);
    printf("Now x = %d and y = %d.\n", x, y);
    
    return 0;
}

void interchange(int u, int v)  /* define function  */
{
    int temp;
    
    temp = u;
    u = v;
    v = temp;
}

/* swap2.c -- 查找 swap1.c的问题 */
void interchange2(int u, int v);
int swap2(void)
{
    int x = 5, y = 10;
    
    printf("Originally x = %d and y = %d.\n", x , y);
    interchange2(x, y);
    printf("Now x = %d and y = %d.\n", x, y);
    
    return 0;
}

void interchange2(int u, int v)
{
    int temp;
    
    printf("Originally u = %d and v = %d.\n", u , v);
    temp = u;
    u = v;
    v = temp;
    printf("Now u = %d and v = %d.\n", u, v);
}

/* swap3.c -- 指针交换 */
void interchange3(int *u, int *v);
int swap3(void)
{
    int x = 5, y = 10;
    printf("Originally x = %d and y = %d.\n", x , y);
    interchange3(&x, &y);
    printf("Now x = %d and y = %d.\n", x, y);
    return 0;
}

void interchange3(int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}

int main(int argc, const char * argv[]) {
    
//    lethead1();
//    lethead2();
//    lesser();
//    misuse();
//    proto();
//    recur();
//    factor();
//    binary();
//    usehotel();
//    loccheck();
//    swap1();
//    swap2();
    swap3();
    return 0;
}
