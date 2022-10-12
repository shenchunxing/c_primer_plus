//
//  main.c
//  Chapter8
//
//  Created by 沈春兴 on 2022/10/9.
//

#include <stdio.h>

/* echo.c -- repeats input */
int echo(void)
{
    char ch;
    
    while ((ch = getchar()) != '#')
        putchar(ch);
    
    return 0;
}

/* echo_eof.c -- repeats input to end of file */
int echo_eof(void)
{
    int ch;
    
    while ((ch = getchar()) != EOF) //EOF : ctrl + d
        putchar(ch);
    
    return 0;
}

// file_eof.c --open a file and display it
#include <stdlib.h>  // for exit()
int file_eof()
{
    int ch;
    FILE * fp;
    char fname[50];         // to hold the file name
    
    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // open file for reading
    if (fp == NULL)         // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(1);            // quit program
    }
    // getc(fp) gets a character from the open file
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);             // close the file
    
    return 0;
}

/* guess.c -- an inefficient and faulty number-guesser */
int guess(void)
{
    int guess = 1;
    
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %d?\n", guess);
    while (getchar() != 'y')      /* get response, compare to y */
        printf("Well, then, is it %d?\n", ++guess);
    printf("I knew I could do it!\n");
    
    return 0;
}

/* showchar1.c -- program with a BIG I/O problem,没有输入第二次就直接退出了 */
void display(char cr, int lines, int width);
int showchar1(void)
{
    int ch;             /* character to be printed    */
    int rows, cols;     /* number of rows and columns */
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        display(ch, rows, cols);
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
    
    return 0;
}

void display(char cr, int lines, int width)
{
    int row, col;
    
    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        putchar('\n');  /* end line and start a new one */
    }
}

/* showchar2.c -- prints characters in rows and columns */
int showchar2(void)
{
    int ch;             /* character to be printed      */
    int rows, cols;     /* number of rows and columns   */
    
    printf("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        if (scanf("%d %d",&rows, &cols) != 2)
            break;
        display(ch, rows, cols);
        while (getchar() !=  '\n') //跳过上一轮结束后的'\n'字符，否则会直接退出
            continue;
        printf("Enter another character and two integers;\n");
        printf("Enter a newline to quit.\n");
    }
    printf("Bye.\n");
    
    return 0;
}

// checking.c -- validating input
#include <stdbool.h>
// validate that input is an integer
long get_long(void);
// validate that range limits are valid
bool bad_limits(long begin, long end,
                long low, long high);
// calculate the sum of the squares of the integers
// a through b
double sum_squares(long a, long b);
int checking(void)
{
    const long MIN = -10000000L;  // lower limit to range
    const long MAX = +10000000L;  // upper limit to range
    long start;                   // start of range
    long stop;                    // end of range
    double answer;
    
    printf("This program computes the sum of the squares of "
           "integers in a range.\nThe lower bound should not "
           "be less than -10000000 and\nthe upper bound "
           "should not be more than +10000000.\nEnter the "
           "limits (enter 0 for both limits to quit):\n"
           "lower limit: ");
    start = get_long();
    printf("upper limit: ");
    stop = get_long();
    while (start !=0 || stop != 0)
    {
        if (bad_limits(start, stop, MIN, MAX))
            printf("Please try again.\n");
        else
        {
            answer = sum_squares(start, stop);
            printf("The sum of the squares of the integers ");
            printf("from %ld to %ld is %g\n",
                    start, stop, answer);
        }
        printf("Enter the limits (enter 0 for both "
               "limits to quit):\n");
        printf("lower limit: ");
        start = get_long();
        printf("upper limit: ");
        stop = get_long();
    }
    printf("Done.\n");
    
    return 0;
}

//获取长度
long get_long(void)
{
    long input;
    char ch;
    
    while (scanf("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    
    return input;
}
//平方和
double sum_squares(long a, long b)
{
    double total = 0;
    long i;
    
    for (i = a; i <= b; i++)
        total += (double)i * (double)i;
    
    return total;
}

//校验
bool bad_limits(long begin, long end,
                long low, long high)
{
    bool not_good = false;
    
    if (begin > end)
    {
        printf("%ld isn't smaller than %ld.\n", begin, end);
        not_good = true;
    }
    if (begin < low || end < low)
    {
        printf("Values must be %ld or greater.\n", low);
        not_good = true;
    }
    if (begin > high || end > high)
    {
        printf("Values must be %ld or less.\n", high);
        not_good = true;
    }
    
    return not_good;
}

/* menuette.c -- menu techniques */
int get_int(void)
{
    int input;
    char ch;
    
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);  // dispose of bad input
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    
    return input;
}

//获取第一个字符
char get_first(void)
{
    int ch;
    
    ch = getchar();
    while (getchar() != '\n')
        continue;
    
    return ch;
}

//计数
void count(void)
{
    int n,i;
    
    printf("Count how far? Enter an integer:\n");
    n = get_int();
    for (i = 1; i <= n; i++)
        printf("%d\n", i);
    while ( getchar() != '\n')
        continue;
}

//选择一个选项
char get_choice(void)
{
    int ch;
    
    printf("Enter the letter of your choice:\n");
    printf("a. advice           b. bell\n");
    printf("c. count            q. quit\n");
    ch = get_first();
    while (  (ch < 'a' || ch > 'c') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    
    return ch;
}

int menuette(void)
{
    int choice;
    void count(void);
    
    while ( (choice = get_choice()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  printf("Buy low, sell high.\n");
                break;
            case 'b' :  putchar('\a');  /* ANSI */
                break;
            case 'c' :  count();
                break;
            default  :  printf("Program error!\n");
                break;
        }
    }
    printf("Bye.\n");
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
//    echo();
//    echo_eof();
//    file_eof();
//    guess();
//    showchar1();
//    showchar2();
//    checking();
    menuette();
    
    return 0;
}
