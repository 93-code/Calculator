#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    char *p;
    int result;
    //test
    char buf[1024]="11 +12/3 +1  +2";

    printf("Input the experssion!\n");
    gets(buf);

    p = buf;

    printf(".......................\n");
    result = Scan_char_Cal(p);
    printf("%s = %d \n",buf,result);

    return 0;
}
