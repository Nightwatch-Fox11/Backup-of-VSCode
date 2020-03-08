#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

void odd_even(SeqList *L)
{
    for (int i = 0, j = L->last; i < j;)
    {
        while (L->elem[i] % 2)
        {
            i++;
        }
        while (L->elem[j] % 2 == 0)
        {
            j--;
        }
        int t = L->elem[i];
        L->elem[i] = L->elem[j];
        L->elem[j] = t;
    }
}
