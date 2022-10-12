//
//  addaword.c
//  Chapter13
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "addaword.h"
/* addaword.c -- 使用 fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int addaword(void)
{
    FILE *fp;
    char words[MAX];
    
    if ((fp = fopen("wordy", "a+")) == NULL) //可以进行读写操作
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s", words) == 1)  && (words[0] != '#'))
        fprintf(fp, "%s\n", words);
    
    puts("File contents:");
    rewind(fp);           /* 返回到文件开始处 */
    while (fscanf(fp,"%s",words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    
    return 0;
}
