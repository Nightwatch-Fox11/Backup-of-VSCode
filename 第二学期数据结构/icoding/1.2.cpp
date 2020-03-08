#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

void del_dupnum(SeqList *L)
{
    int j = 0;
    for (int i = 0; i <= L->last; i++)
    {
        if (i != 0 && L->elem[i] == L->elem[i - 1])
        {
            j++;
        }
        else
        {
            L->elem[i - j] = L->elem[i];
        }
    }
    L->last -= j;
}