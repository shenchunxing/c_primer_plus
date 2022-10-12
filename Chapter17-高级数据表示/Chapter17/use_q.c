//
//  use_q.c
//  Chapter17
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "use_q.h"
/* use_q.c -- 测试队列接口 */
/* compile with queue.c                          */
#include <stdio.h>
#include "queue.h"  /* defines Queue, Item       */

int use_q(void)
{
    Queue line;
    Item temp;
    char ch;
    
    InitializeQueue(&line); //初始化队列
    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");
    while ((ch = getchar()) != 'q')
    {
        if (ch != 'a' && ch != 'd')   /* ignore other input */
            continue;
        if ( ch == 'a')
        {
            printf("Integer to add: ");
            scanf("%d", &temp);
            if (!QueueIsFull(&line))
            {
                printf("Putting %d into queue\n", temp);
                EnQueue(temp,&line);
            }
            else
                puts("Queue is full!");
        }
        else
        {
            if (QueueIsEmpty(&line))
                puts("Nothing to delete!");
            else
            {
                DeQueue(&temp,&line);
                printf("Removing %d from queue\n", temp);
            }
        }
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit:");
    }
    EmptyTheQueue(&line);
    puts("Bye!");
    
    return 0;
}
