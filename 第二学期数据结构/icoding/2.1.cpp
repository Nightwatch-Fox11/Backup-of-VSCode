#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

typedef struct _QueueNode
{
    ElemType data;           /*数据域*/
    struct _QueueNode *next; /*指针域*/
} LinkQueueNode, *LinkQueue;
bool init_queue(LinkQueue *LQ)
{
    *LQ = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (*LQ)
    {
        (*LQ)->next = *LQ;
        return true;
    }
    else
    {
        return false;
    }
}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
    LinkQueue r;
    r = (LinkQueue)malloc(sizeof(LinkQueue));
    if (!r)
    {
        return false;
    }
    else
    {
        r->data = x;
        r->next = (*LQ)->next;
        (*LQ)->next = r;
        (*LQ) = r;
        return true;
    }
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
    if ((*LQ)->next == (*LQ))
    {
        return false;
    }
    else
    {
        LinkQueue p;
        p = (*LQ)->next->next;
        (*x) = p->data;
        if ((*LQ) == p)
        {
            (*LQ) = (*LQ)->next;
            (*LQ)->next = (*LQ);
        }
        else
        {
            (*LQ)->next->next = p->next;
        }
        free(p);
        return true;
    }
}
