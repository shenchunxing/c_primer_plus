//
//  fields.c
//  Chapter15
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "fields.h"
/* fields.c -- 定义并使用位字段 */
#include <stdio.h>
#include <stdbool.h>   //C99, defines bool, true, false

/* 线的样式     */
#define SOLID   0
#define DOTTED  1
#define DASHED  2
/* 三原色  */
#define BLUE    4
#define GREEN   2
#define RED     1
/* 混合色    */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow",
    "blue", "magenta", "cyan", "white"};

struct box_props { //结构一共占用16位
    bool opaque                 : 1;  // or unsigned int (pre C99)
    unsigned int fill_color     : 3; //3位即有8种组合RGB
    unsigned int                : 4; //空隙
    bool show_border            : 1;  // or unsigned int (pre C99)
    unsigned int border_color   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2;//空隙
};

void show_settings(const struct box_props * pb);

int fields(void)
{
    /* 创建并初始化 */
    struct box_props box = {true, YELLOW , true, GREEN, DASHED};
    
    printf("Original box settings:\n");
    show_settings(&box);
    
    //重新赋值
    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);
    
    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n",
           pb->opaque == true ? "opaque": "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n",
           pb->show_border == true ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf ("The border style is ");
    switch(pb->border_style)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}
