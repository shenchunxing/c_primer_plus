/* list.c -- functions supporting list operations */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 拷贝item作为节点的数据 */
static void CopyToNode(Item item, Node * pnode);

/* interface functions   */
/* set the list to empty */
void InitializeList(List * plist)
{
    * plist = NULL;
}

/* 链表为空 */
bool ListIsEmpty(const List * plist)
{
    if (*plist == NULL)
        return true;
    else
        return false;
}

/* 链表是否已满 */
bool ListIsFull(const List * plist)
{
    Node * pt;
    bool full;
    
    pt = (Node *) malloc(sizeof(Node));
    if (pt == NULL)
        full = true;
    else
        full = false;
    free(pt);
    
    return full;
}

/* 链表数量 */
unsigned int ListItemCount(const List * plist)
{
    unsigned int count = 0;
    Node * pnode = *plist;    /* 设置链表开始节点 */
    
    while (pnode != NULL)
    {
        ++count;
        pnode = pnode->next;  /* 设置下一个节点     */
    }
    
    return count;
}

/* creates node to hold item and adds it to the end of */
/* the list pointed to by plist (slow implementation)  */
bool AddItem(Item item, List * plist)
{
    Node * pnew;
    Node * scan = *plist;
    
    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL)
        return false;     /* 失败时，直接退出  */
    
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL)          /* 空链表，设置头节点 */
        *plist = pnew;
    else
    {
        while (scan->next != NULL)
            scan = scan->next;  /* 非空链表，往后拼接    */
        scan->next = pnew;
    }
    
    return true;
}

/* 遍历 */
void Traverse  (const List * plist, void (* pfun)(Item item) )
{
    Node * pnode = *plist;    /* set to start of list   */
    
    while (pnode != NULL)
    {
        (*pfun)(pnode->item); /* apply function to item */
        pnode = pnode->next;  /* advance to next item   */
    }
}

/* free memory allocated by malloc() */
/* set list pointer to NULL          */
void EmptyTheList(List * plist)
{
    Node * psave;
    
    while (*plist != NULL)
    {
        psave = (*plist)->next; /* save address of next node */
        free(*plist);           /* free current node         */
        *plist = psave;         /* advance to next node      */
    }
}

/* local function definition  */
/* copies an item into a node */
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;  /* structure copy */
}
