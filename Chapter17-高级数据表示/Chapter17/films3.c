//
//  films3.c
//  Chapter17
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "films3.h"
/* films3.c -- 使用抽象数据类型的链表 */
/* compile with list.c                        */
#include <stdio.h>
#include <stdlib.h>    /* prototype for exit() */
#include "list.h"      /* defines List, Item   */
void showmovies(Item item);
char * s_gets(char * st, int n);
int films3(void)
{
    List movies;
    Item temp;
    
    
    /* 初始化       */
    InitializeList(&movies);
    if (ListIsFull(&movies))
    {
        fprintf(stderr,"No memory available! Bye!\n");
        exit(1);
    }
    
    /* gather and store */
    puts("Enter first movie title:");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
    {
        puts("Enter your rating <0-10>:");
        scanf("%d", &temp.rating);
        while(getchar() != '\n')
            continue;
        //添加节点
        if (AddItem(temp, &movies)==false)
        {
            fprintf(stderr,"Problem allocating memory\n");
            break;
        }
        //判断是否已满
        if (ListIsFull(&movies))
        {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop):");
    }
    
    /* 显示          */
    if (ListIsEmpty(&movies))
        printf("No data entered. ");
    else
    {
        printf ("Here is the movie list:\n");
        //遍历
        Traverse(&movies, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));
    
    
    /* 清空链表       */
    EmptyTheList(&movies);
    printf("Bye!\n");
    
    return 0;
}

//遍历方式
void showmovies(Item item)
{
    printf("Movie: %s  Rating: %d\n", item.title,
           item.rating);
}

