#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h" // 请不要删除，否则检查不通过
#define Stack_Size 50
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;

bool push(Stack *S, ElemType x);
bool pop(Stack *S, ElemType *x);
void init_stack(Stack *S);

void init_stack(Stack *S)
{
    S->top = -1;
}
int compute_reverse_polish_notation(char *str)
{
    Stack s;
    int x, y;
    init_stack(&s);
    char *pch = strtok(str, "  ");
    while (pch != NULL)
    {
        if (pch[0] != '+' && pch[0] != '%' && pch[0] != '/' && pch[0] != '*' && pch[0] != '-')
        {
            int val = atoi(pch);
            push(&s, val);
        }
        else
        {
            pop(&s, &x);
            pop(&s, &y);
            if (pch[0] == '+')
            {
                push(&s, x + y);
            }
            else if (pch[0] == '-')
            {
                push(&s, y - x);
            }
            else if (pch[0] == '*')
            {
                push(&s, x * y);
            }
            else if (pch[0] == '/')
            {
                push(&s, y / x);
            }
            else if (pch[0] == '%')
            {
                push(&s, y % x);
            }
        }
        pch = strtok(NULL, "  ");
    }
    return s.elem[s.top];
}
