//
//  main.c
//  Chapter11
//
//  Created by 沈春兴 on 2022/10/10.
//

#include <stdio.h>
#include "put_put.h"
#include "test_fit.h"
#include "str_cat.h"
#include "join_chk.h"
#include "nogo.h"
#include "compback.h"
#include "quick_chk.h"
#include "starsrch.h"
#include "copy1.h"
#include "format.h"
#include "sort_str.h"
#include "mod_str.h"
#include "repeat.h"
#include "strcnvt.h"

//  strings1.c
#include <stdio.h>
#define MSG "I am a symbolic string constant."
#define MAXLENGTH 81
int strings1(void)
{
    char words[MAXLENGTH] = "I am a string in an array.";
    const char * pt1 = "Something is pointing at me.";
    puts("Here are some strings:");
    puts(MSG);
    puts(words);
    puts(pt1);
    words[8] = 'p';
    puts(words);//I am a spring in an array.
//puts和printf不同的是，puts只能打印字符串
    return 0;
}

/* strptr.c -- 把字符串当指针 */
#include <stdio.h>
int strptr(void)
{
    printf("%s, %p, %c\n", "We", "are", *"space farers");//*"space farers"表示该字符串存储的首地址的值，也就是s
    
    return 0;
}

//  addresses.c  -- 字符串的地址
#define MSG2 "I'm special."
#include <stdio.h>
int addresses(void)
{
    char ar[] = MSG2;//动态内存地址和常量字符串肯定不同，
    const char *pt = MSG2;
    printf("address of \"I'm special\": %p \n", "I'm special.");
    printf("              address ar: %p\n", ar);
    printf("              address pt: %p\n", pt);
    printf("          address of MSG: %p\n", MSG2);
    printf("address of \"I'm special\": %p \n", "I'm special.");

    return 0;
}

//  arrchar.c -- 指针数组、字符串数组
#include <stdio.h>
#define SLEN 40
#define LIM 5
int arrchar(void)
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately", "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping", "Watching television",
        "Mailing letters", "Reading email"
    };
    int i;
    
    puts("Let's compare talents.");
    printf ("%-36s  %-25s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i++)
        printf("%-36s  %-25s\n", mytalents[i], yourtalents[i]);
    printf("\nsizeof mytalents: %zd, sizeof yourtalents: %zd\n",
           sizeof(mytalents), sizeof(yourtalents));//sizeof mytalents: 40(指针 * 5), sizeof yourtalents: 200(数组大小40 * 5),
    
    return 0;
}

/* p_and_s.c -- 指针和字符串 */
#include <stdio.h>
int p_and_s(void)
{
    const char * mesg = "Don't be a fool!";
    const char * copy;
    
    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n",
           mesg, &mesg, mesg);//mesg = Don't be a fool!; &mesg = 0x3040cb2a8; value = 0x100003f4f
    printf("copy = %s; &copy = %p; value = %p\n",
           copy, &copy, copy);//copy = Don't be a fool!; &copy = 0x3040cb2a0; value = 0x100003f4f
     
    return 0;
}

/*  getsputs.c  -- 使用 gets() 和 puts() */
#include <stdio.h>
#define STLEN 81
int getsputs(void)
{
    char words[STLEN];
     
    puts("Enter a string, please.");
    gets(words);  // typical use
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");
    
    return 0;
}

/*  fgets1.c  -- 使用 fgets() 和 fputs() */
#include <stdio.h>
#define STLEN2 14
int fgets1(void)
{
    char words[STLEN2];
    
    puts("Enter a string, please.");
    fgets(words, STLEN2, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN2, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
    
    return 0;
}

/*  fgets2.c  -- 使用 fgets() 和 fputs() */
#include <stdio.h>
#define STLEN3 10
int fgets2(void)
{
    char words[STLEN3];
    
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN3, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Done.");
    
    return 0;
}

/*  fgets3.c  -- 使用 fgets() */
#include <stdio.h>
int fgets3(void)
{
    char words[STLEN3];
    int i;
    
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN3, stdin) != NULL
                          && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0') //遍历，直到遇到换行符或者空符
            i++;
        if (words[i] == '\n') //遇到的是换行符
            words[i] = '\0';//替换为空符
        else // 遇到的是空符
            while (getchar() != '\n') //读取缓冲区的每一个字符，但不存储输入，丢弃剩余的输入字符
                continue;
        puts(words);
    }
    puts("done");
    return 0;
}

/* scan_str.c -- 使用 scanf() */
#include <stdio.h>
int scan_str(void)
{
    char name1[11], name2[11];
    int count;
    
    printf("Please enter 2 names.\n");
    count = scanf("%5s %10s",name1, name2);
    printf("I read the %d names %s and %s.\n",
           count, name1, name2);
    
    return 0;
}

/* put_out.c -- 使用 puts() */
#include <stdio.h>
#define DEF "I am a #defined string."
int put_out(void)
{
    char str1[80] = "An array was initialized to me.";
    const char * str2 = "A pointer was initialized to me.";
    
    puts("I'm an argument to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);//puts从第6个元素开始输出：ray was initialized to me.
    puts(str2+4);
    
    return 0;
}

/* nono.c -- 千万不要模仿！ */
#include <stdio.h>
int nono(void)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!' };//缺少一个空结束符
    char side_b[] = "Side B";
    
    puts(dont);   /* dont is not a string */
    
    return 0;
}

int main(int argc, const char * argv[]) {
   
//    strings1();
//    strptr();
//    addresses();
//    arrchar();
//    p_and_s();
//    getsputs();
//    fgets1();
//    fgets2();
//    fgets3();
//    scan_str();
//    put_out();
//    nono();
//    put_put()
//    test_fit();
//    str_cat();
//    join_chk();
//    nogo();
//    compare();
//    compback();
//    quick_chk();
//    starsrch();
//    copy1();
//    copy2();
//    copy3();
//    format();
//    sort_str();
//    mod_str();
    
    //带参数的main函数
    //argc:1
    //argv：文件地址
//    printf("argc = %d argv = %s ",argc,*argv);
    
    strcnvt();
    
    return 0;
}
