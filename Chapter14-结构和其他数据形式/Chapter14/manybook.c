//
//  manybook.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "manybook.h"
/* manybook.c -- 多本书目录 */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL2   40
#define MAXAUTL2   40
#define MAXBKS2   100              /* maximum number of books  */

struct book2 {                     /* set up book template     */
    char title[MAXTITL2];
    char author[MAXAUTL2];
    float value;
};

int manybook(void)
{
    struct book2 library[MAXBKS2]; /* array of book structures */
    int count = 0;
    int index;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS2 && s_gets(library[count].title, MAXTITL2) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL2);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS2)
            printf("Enter the next title.\n");
    }
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
    }
    else
        printf("No books? Too bad.\n");
    
    return 0;
}

