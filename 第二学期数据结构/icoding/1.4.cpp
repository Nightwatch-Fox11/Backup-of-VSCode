#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过
struct _lnklist
{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    LinkList pre = L;
    LinkList cur = L->next;
    while (cur != NULL)
    {
        if (cur->data > mink && cur->data < maxk)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = pre->next;
            cur = pre->next;
        }
    }
}
