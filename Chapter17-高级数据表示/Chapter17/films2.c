//
//  films2.c
//  Chapter17
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "films2.h"
/* films2.c -- 使用链表结构 */
#include <stdio.h>
#include <stdlib.h>      /* has the malloc prototype      */
#include <string.h>      /* has the strcpy prototype      */
#define TSIZE    45      /* 限制片名大小   */

struct film2 {
    char title[TSIZE];
    int rating;
    struct film2 * next;  /*指向链表的下一个指针 */
};
char * s_gets(char * st, int n);
int films2(void)
{
    struct film2 * head = NULL; //头结点
    struct film2 * prev, * current;//上一个节点、当前节点
    char input[TSIZE];
    
    /* 收集并存储信息          */
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        //动态创建
        current = (struct film2 *) malloc(sizeof(struct film2));
        if (head == NULL)       /* 头结点     */
            head = current;
        else                    /* 后续节点 */
            prev->next = current;
        current->next = NULL;
        //设置标题
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        //输入排名
        scanf("%d", &current->rating);
        while(getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current; //将当前节点设置为上一个节点
    }
    
    /*显示电影列表  */
    if (head == NULL)
        printf("No data entered. ");
    else
        printf ("Here is the movie list:\n");
    //当前指针指向头结点
    current = head;
    //遍历链表
    while (current != NULL)
    {
        printf("Movie: %s  Rating: %d\n",
               current->title, current->rating);
        current = current->next;
    }
    
    /* 完成任务。遍历释放链表 */
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("Bye!\n");
    
    return 0;
}
