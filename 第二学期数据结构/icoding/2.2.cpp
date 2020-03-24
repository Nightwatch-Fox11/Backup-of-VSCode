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
    while (pch != NULL)
    {
        char *pch = strtok(str, " ");
        int val = atoi(pch);
        pch = strtok(NULL, " ");
    }
}