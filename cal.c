#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
    int opt1,opt2;
    /*char buf[] = "4+6/2";*/
    char buf[1024];

    printf("Input the experssion!\n");
    gets(buf);

    LinkStack *operand_stack = Create_empty_Stack(); 
    LinkStack *operator_stack = Create_empty_Stack();

    char *p = buf;
    printf(".......................\n");
    while (*p != '\0')
    {
        if (*p >= '0' && *p <= '9')
        {
            Push_LinkStack(operand_stack,*p-'0');
        }
        else
        {
            switch (*p)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                if (!Is_empty_Stack(operator_stack))
                {
                    opt1 = Get_Level(*p);
                    opt2 = Get_Level(Get_top_Data(operator_stack)); 
                    if (opt1 > opt2)
                    {
                        Push_LinkStack(operator_stack,*p);
                    }
                    else
                    {
                        compute(operand_stack,operator_stack);
                        Push_LinkStack(operator_stack,*p);
                    }
                }
                else
                {
                    Push_LinkStack(operator_stack,*p);
                }
                break;
            default:
                printf("Error char %c\n",*p);
            }
        }
        p++;
    }
    while (operator_stack->n != 0)
    {
        compute(operand_stack,operator_stack);
    }

    printf("%s = %d \n",buf,Pop_LinkStack(operand_stack));
    return 0;
}
