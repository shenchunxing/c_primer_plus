//
//  enum.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "enum.h"
/* enum.c -- 使用枚举类型 */
#include <stdio.h>
#include <string.h>    // for strcmp(), strchr()
#include <stdbool.h>   // C99 feature
char * s_gets(char * st, int n);

enum spectrum {red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow",
    "green", "blue", "violet"};
#define LEN 30

int enum_(void)
{
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;
    
    puts("Enter a color (empty line to quit):");
    while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++) //枚举默认从0开始
        {
            if (strcmp(choice, colors[color]) == 0) //找到了颜色
            {
                color_is_found = true;
                break;
            }
        }
        if (color_is_found) //没找到颜色
            switch(color)
        {
            case red    : puts("Roses are red.");
                break;
            case orange : puts("Poppies are orange.");
                break;
            case yellow : puts("Sunflowers are yellow.");
                break;
            case green  : puts("Grass is green.");
                break;
            case blue   : puts("Bluebells are blue.");
                break;
            case violet : puts("Violets are violet.");
                break;
        }
        else
            printf("I don't know about the color %s.\n", choice);
        color_is_found = false;
        puts("Next color, please (empty line to quit):");
    }
    puts("Goodbye!");
    
    return 0;
}


