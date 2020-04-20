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
int init_cross_list(PCrossList L, const ElemType *A, int m, int n)
{
    int i, j, k;
    OLNode *p, *q;
    L->rows = m;
    L->cols = n;
    for (k = 0; k < m * n; k++)
    {
        if (A[k])
        {
            L->nums++;
        }
    }
    L->rowhead = (OLink *)malloc((L->rows + 1) * sizeof(OLink));
    L->colhead = (OLink *)malloc((L->cols + 1) * sizeof(OLink));
    // 初始化行链索引为NULL 初始化列链索引为NULL
    L->rowhead = L->colhead = NULL;
    for (k = 0; k < m * n; ++k)
    {
        // 创建三元组结点
        p = (OLNode *)malloc(sizeof(OLNode));
        if (!A[k])
        {
            continue;
        }

        p->value = A[k];
        i = p->row = k % n + 1;             // 行号
        j = p->col = (k - (k % n) * n) + 1; // 列号
        p->right = p->down = NULL;

        /*
         * 开始行的插入
         */

        // 如果该行还没有元素，或已有元素均位于该元素右侧，则可以直接插入
        if (L->rowhead[i] == NULL)
        {
            L->rowhead[i] = p;
        }
        else
        {

            for (q = L->rowhead[i]; (q->right) && (q->right->col < j); q = q->right)
            {
            }
            p->right = q->right;
            q->right = p;
        }

        /*
         * 开始列的插入
         */

        // 如果该列还没有元素，或已有元素均位于该元素下侧，则可以直接插入
        if (L->colhead[j] == NULL)
        {
            L->colhead[j] = p;
        }
        else
        {
            // 寻找插入位置的前一个位置
            for (q = L->colhead[j]; (q->down) && (q->down->row < i); q = q->down)
            {
            }
            p->down = q->down;
            q->down = p;
        }
    }

    return L->nums;
}

int del_cross_list(PCrossList L, ElemType k)
{
    int i, te = 0, co;
    OLNode *tmp = NULL;
    OLNode *tmp1 = NULL;
    OLNode *tmp2 = NULL;
    OLNode *t = NULL;
    OLNode *t1 = NULL;
    OLNode *t2 = NULL;
    // 无论从按行还是按列，只需要朝着一个方向去遍历销毁就可以了
    for (i = 1; i <= L->rows; ++i)
    {
        tmp = L->rowhead[i];
        while (tmp)
        {
            tmp1 = tmp;
            tmp = tmp->right;
            if (tmp && tmp->value == k)
            {
                tmp2 = tmp;
                tmp1->right = tmp2->right;
                co = tmp2->col;
                break;
            }
        }
        t = L->colhead[co];
        //列遍历元素
        while (t)
        {
            t1 = t;
            t = t->down;
            if (t && t->value == k)
            {
                t2 = t;
                t1->down = t2->down;
                break;
            }
        }
        free(tmp2);
        L->nums--;
        te++;
    }

    return te;
}
