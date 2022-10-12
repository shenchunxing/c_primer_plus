//
//  useheader.c
//  Chapter16
//
//  Created by 沈春兴 on 2022/10/11.
//

#include "useheader.h"
// useheader.c -- 使用names_st结构
#include <stdio.h>
#include "names_st.h"
// remember to link with names_st.c

int useheader(void)
{
    names candidate;
    
    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");
    return 0;
}
