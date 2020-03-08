#include <stdio.h>
#include "list.h"
#include <stdlib.h>
struct _seqlist //线性表定义
{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;
void delete (SeqList L, int k, int i)
{
    if (i + k - 1 >= L->last) //删除区域超过last
    {
        L->last -= k;
    }
    else
    {
        for (int j = i; j + k <= L->last; j++) //删除区域未超过last
        {
            L->elem[j] = L->elem[j + k];
        }
        L->last -= k;
    }
}