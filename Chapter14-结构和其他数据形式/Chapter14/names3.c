//
//  names3.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "names3.h"
// names3.c -- 使用指针 和 malloc()
#include <stdio.h>
#include <string.h>   // for strcpy(), strlen()
#include <stdlib.h>   // for malloc(), free()
#define SLEN 81
struct namect3 {
    char * fname;  // 使用指针
    char * lname;
    int letters;
};

void getinfo3(struct namect3 *);        // allocates memory
void makeinfo3(struct namect3 *);
void showinfo3(const struct namect3 *);
void cleanup3(struct namect3 *);        // free memory when done
char * s_gets(char * st, int n);

int namect3_(void)
{
    struct namect3 person;
    
    getinfo3(&person);
    makeinfo3(&person);
    showinfo3(&person);
    cleanup3(&person);
    
    return 0;
}

void getinfo3 (struct namect3 * pst)
{
    char temp[SLEN];
    printf("Please enter your first name.\n");
    s_gets(temp, SLEN);
    // 分配内存来存储名字
    pst->fname = (char *) malloc(strlen(temp) + 1);
    // 把名字拷贝到动态内存中
    strcpy(pst->fname, temp);
    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char *) malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}

void makeinfo3 (struct namect3 * pst)
{
    pst->letters = strlen(pst->fname) +
    strlen(pst->lname);
}

void showinfo3 (const struct namect3 * pst)
{
    printf("%s %s, your name contains %d letters.\n",
           pst->fname, pst->lname, pst->letters);
}

void cleanup3(struct namect3 * pst)
{
    free(pst->fname);
    free(pst->lname);
}


