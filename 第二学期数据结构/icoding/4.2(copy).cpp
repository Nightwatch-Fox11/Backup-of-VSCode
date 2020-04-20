#include <stdio.h>
#include <stdlib.h>
#include "crosslist.h"
typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode
{
    int row, col;
    ElemType value;
    struct OLNode *right, *down;
} OLNode, *OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead, *colhead;
    int rows, cols, nums;
} CrossList, *PCrossList;
//copy
int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
    int i = 0, j = 0, k = 0, cnt = 0;
    OLink p1, p2, p;
    L->rowhead = (OLink *)malloc(sizeof(OLink) * m);
    L->colhead = (OLink *)malloc(sizeof(OLink) * n);
    for (i = 0; i < m; ++i)
    {
        L->rowhead[i] = NULL;
    }
    for (i = 0; i < n; ++i)
    {
        L->colhead[i] = NULL;
    }
    for (i = 0; i < m; ++i)
    {
        p1 = L->rowhead[i];
        for (j = 0; j < n; ++j)
        {
            if (A[i * n + j] == 0)
                continue;
            cnt++;
            p = (OLink)malloc(sizeof(OLNode));
            p->row = i;
            p->col = j;
            p->value = A[i * n + j];
            p->down = NULL;
            p->right = NULL;
            if (p1 == NULL)
            {
                L->rowhead[i] = p;
                p1 = p;
            }
            else
            {
                p1->right = p;
                p1 = p;
            }
            p2 = L->colhead[j];
            if (p2 == NULL)
                L->colhead[j] = p;
            else
            {
                while (p2->down != NULL && p2->down->row < i)
                    p2 = p2->down;
                p->down = p2->down;
                p2->down = p;
            }
        }
    }
    L->nums = cnt;
    L->rows = m;
    L->cols = n;
    return cnt;
}
int del_cross_list(PCrossList L, ElemType k)
{
    int i, cnt = 0;
    OLink p1, p, p2;
    for (i = 0; i < L->rows; ++i)
    {
        p1 = L->rowhead[i];
        p = p1;
        while (p1 != NULL)
        {
            if (p1->value == k)
            {
                if (p1 == L->rowhead[i])
                {
                    L->rowhead[i] = p1->right;
                    p = L->rowhead[i];
                }
                else
                {
                    p->right = p1->right;
                }
            }
            else
                p = p1;
            p1 = p1->right;
        }
    }
    for (i = 0; i < L->cols; ++i)
    {
        p1 = L->colhead[i];
        p2 = p1;
        while (p1 != NULL)
        {
            if (p1->value == k)
            {
                if (p1 == L->colhead[i])
                {
                    p = p1;
                    L->colhead[i] = p1->down;
                    p2 = L->colhead[i];
                    p1 = p2;
                }
                else
                {
                    p = p1;
                    p2->down = p1->down;
                    p1 = p1->down;
                }
                free(p);
                cnt++;
            }
            else
            {
                p2 = p1;
                p1 = p1->down;
            }
        }
    }
    return cnt;
}