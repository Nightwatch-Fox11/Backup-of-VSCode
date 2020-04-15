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
    L->nums = m * n;
    L->rowhead = (OLink *)malloc((L->rows + 1) * sizeof(OLink));
    if (L->rowhead == NULL)
    {
        return 0;
    }
    L->colhead = (OLink *)malloc((L->cols + 1) * sizeof(OLink));
    if (L->colhead == NULL)
    {
        return 0;
    }
    // 初始化行链索引为NULL
    for (k = 0; k <= m; ++k)
    {
        L->rowhead[k] = NULL;
    }
    // 初始化列链索引为NULL
    for (k = 0; k <= n; ++k)
    {
        L->colhead[k] = NULL;
    }
    for (k = 0; k < L->nums; ++k)
    {
        // 创建三元组结点
        p = (OLNode *)malloc(sizeof(OLNode));
        if (p == NULL)
        {
            return 0;
        }
        i = p->row = k % m + 1; // 行号
        j = p->col = k % n + 1; // 列号
        p->right = p->down = NULL;

        /*
         * 开始行的插入
         */

        // 如果该行还没有元素，或已有元素均位于该元素右侧，则可以直接插入
        if (L->rowhead[k % m + 1] == NULL || L->rowhead[k % m + 1]->col > k % n + 1)
        {
            // 定位行表中的插入位置
            p->right = L->rowhead[i];
            L->rowhead[i] = p;
        }
        else
        {
            // 寻找插入位置的前一个位置
            for (q = (*M).rhead[i]; (q->right) && (q->right->j < j); q = q->right)
            {
            }

            if (q->j == p->j || ((q->right) && q->right->j == p->j))
            {
                printf("此位置已被占用！！\n");
                exit(ERROR);
            }

            p->right = q->right;
            q->right = p;
        }

        /*
         * 开始列的插入
         */

        // 如果该列还没有元素，或已有元素均位于该元素下侧，则可以直接插入
        if ((*M).chead[j] == NULL || (*M).chead[j]->i > i)
        {
            // 定位列表中的插入位置
            p->down = (*M).chead[j];
            (*M).chead[j] = p;
        }
        else
        {
            // 寻找插入位置的前一个位置
            for (q = (*M).chead[j]; (q->down) && (q->down->i < i); q = q->down)
            {
            }

            if (q->i == p->i || ((q->down) && q->down->i == p->i))
            {
                printf("此位置已被占用！！\n");
                exit(ERROR);
            }

            p->down = q->down;
            q->down = p;
        }
    }

    if (!readFromConsole)
    {
        fclose(fp);
    }

    return OK;
}
}

int del_cross_list(PCrossList L, ElemType k)
{
}