//
//  booksave.c
//  Chapter14
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "booksave.h"
/* booksave.c -- 在文件中保存结构内容 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL  40
#define MAXAUTL  40
#define MAXBKS   10             /* maximum number of books */
char * s_gets(char * st, int n);
struct book5 {                   /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int booksave(void)
{
    struct book5 library[MAXBKS]; /* array of structures     */
    int count = 0;
    int index, filecount;
    FILE * pbooks;
    int size = sizeof (struct book5);
    
    if ((pbooks = fopen("book.dat", "a+b")) == NULL)
    {
        fputs("Can't open book.dat file\n",stderr);
        exit(1);
    }
    
    rewind(pbooks);            /* go to start of file     */
    while (count < MAXBKS &&  fread(&library[count], size,
                                    1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n",library[count].title,
               library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;                /* clear input line  */
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n",library[index].title,
                   library[index].author, library[index].value);
        fwrite(&library[filecount], size, count - filecount,
               pbooks);
    }
    else
        puts("No books? Too bad.\n");
    
    puts("Bye.\n");
    fclose(pbooks);
    
    return 0;
}


