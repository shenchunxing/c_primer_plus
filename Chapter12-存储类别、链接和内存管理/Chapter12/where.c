//
//  where.c
//  Chapter12
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "where.h"
//  where.c  -- 数据被存储在何处?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "String Literal";
int where()
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int * pi;
    char * pcl;
    
    pi = (int *) malloc(sizeof(int));
    *pi = 35;
    pcl = (char *) malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");
    
    printf("static_store: %d at %p\n", static_store, &static_store); //全局区
    printf("  auto_store: %d at %p\n", auto_store, &auto_store);//栈
    printf("         *pi: %d at %p\n", *pi, pi);//堆
    printf("  %s at %p\n", pcg, pcg);//常量字符串，全局区
    printf(" %s at %p\n", auto_string, auto_string);//栈
    printf("  %s at %p\n", pcl, pcl);//堆
    printf("   %s at %p\n", "Quoted String", "Quoted String");//常量字符串，全局区
    free(pi);
    free(pcl);
    
    return 0;
}
