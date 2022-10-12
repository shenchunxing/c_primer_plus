//
//  main.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/10.
//

#include <stdio.h>
#include "parta.h"
#include "r_drive0.h"
#include "r_drive1.h"
#include "manydice.h"
#include "dyn_arr.h"
#include "where.h"

// hiding.c -- 块中的变量
#include <stdio.h>
int hiding()
{
    int x = 30;      // original x
    
    printf("x in outer block: %d at %p\n", x, &x);
    {
        int x = 77;  // new x, hides first x
        printf("x in inner block: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);
    while (x++ < 33) // original x
    {
        int x = 100; // new x, hides first x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }
    printf("x in outer block: %d at %p\n", x, &x);

    return 0;
}

// forc99.c -- 新的 C99 块规则
#include <stdio.h>
int forc99()
{
    int n = 8;
    
    printf("   Initially, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n++)
        printf("      loop 1: n = %d at %p\n", n, &n);
    printf("After loop 1, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n++)
    {
        printf(" loop 2 index n = %d at %p\n", n, &n);
        int n = 6;
        printf("      loop 2: n = %d at %p\n", n, &n);
        n++;
    }
    printf("After loop 2, n = %d at %p\n", n, &n);
    
    return 0;
}

/* loc_stat.c -- 使用局部静态变量 */
#include <stdio.h>
void trystat(void);

int loc_stat(void)
{
    int count;
    
    for (count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        trystat();
    }
    
    return 0;
}

void trystat(void)
{
    int fade = 1;
    static int stay = 1;
    
    printf("fade = %d and stay = %d\n", fade++, stay++);
}


/* global.c  --使用外部变量 */
#include <stdio.h>
int units = 0;         /* an external variable      */
void critic(void);
int global(void)
{
    extern int units;  /* an optional redeclaration */
    
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while ( units != 56)
        critic();
    printf("You must have looked it up!\n");
    
    return 0;
}

void critic(void)
{
    /* optional redeclaration omitted */
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}

int main(int argc, const char * argv[]) {
    
//    hiding();
//    forc99();
//    loc_stat();
//    global();
//    parta();
//    r_drive0(); //伪随机数，每次执行的结果都一样
//    r_drive1();
    
//    manydice();
//    dyn_arr();
    where();
    
    return 0;
}
