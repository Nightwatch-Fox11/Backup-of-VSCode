#include <stdio.h>
#include <stdlib.h>
struct _lnklist
{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_merge(LinkList A, LinkList B, LinkList C)
{
    Node *p = A->next;
    Node *q = B->next;
    Node *r;
    C = A;
    C->next = NULL;
    r = C;
    int i = 1;
    while (p != NULL && q != NULL)
    {
        if (i % 2)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        i++;
    }
    if (p)
    {
        r->next = p;
    }
    else
    {
        r->next = q;
    }
    free(B);
}
