//
//  names2.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "names2.h"
/* names2.c -- 传递并返回结构 */
#include <stdio.h>
#include <string.h>

#define NLEN 30
struct namect2 {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

struct namect2 getinfo2(void);
struct namect2 makeinfo2(struct namect2);
void showinfo2(struct namect2);
char * s_gets(char * st, int n);

int names2_(void)
{
    struct namect2 person;
    
    person = getinfo2();
    person = makeinfo2(person);
    showinfo2(person);
    
    return 0;
}

struct namect2 getinfo2(void)
{
    struct namect2 temp;
    printf("Please enter your first name.\n");
    s_gets(temp.fname, NLEN);
    printf("Please enter your last name.\n");
    s_gets(temp.lname, NLEN);
    
    return temp;
}

struct namect2 makeinfo2(struct namect2 info)
{
    info.letters = strlen(info.fname) + strlen(info.lname);
    
    return info;
}

void showinfo2(struct namect2 info)
{
    printf("%s %s, your name contains %d letters.\n",
           info.fname, info.lname, info.letters);
}
