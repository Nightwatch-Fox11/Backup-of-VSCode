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
}

int del_cross_list(PCrossList L, ElemType k)
{
}
int CreateSMatrix(CrossList *M, char *path)
{
    int i, j, k;
    OLNode *p, *q;
    FILE *fp;
    int readFromConsole; // 是否从控制台读取数据

    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    if (readFromConsole)
    {
        printf("请输入行数：");
        scanf("%d", &((*M).mu));
        printf("请输入列数：");
        scanf("%d", &((*M).nu));
        printf("请输入非零元素个数：");
        scanf("%d", &((*M).tu));
        printf("请输入%d个三元组信息\n", (*M).tu);
    }
    else
    {
        fp = fopen(path, "r");
        ReadData(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));
    }

    // 创建行链（类似行索引，0号单元弃用）
    (*M).rhead = (OLink *)malloc(((*M).mu + 1) * sizeof(OLink));
    if ((*M).rhead == NULL)
    {
        exit(OVERFLOW);
    }

    // 创建列链（类似列索引，0号单元弃用）
    (*M).chead = (OLink *)malloc(((*M).nu + 1) * sizeof(OLink));
    if ((*M).chead == NULL)
    {
        exit(OVERFLOW);
    }

    // 初始化行链索引为NULL
    for (k = 0; k <= (*M).mu; ++k)
    {
        (*M).rhead[k] = NULL;
    }

    // 初始化列链索引为NULL
    for (k = 0; k <= (*M).nu; ++k)
    {
        (*M).chead[k] = NULL;
    }

    // 依次录入非零元
    for (k = 1; k <= (*M).tu; ++k)
    {
        // 创建三元组结点
        p = (OLNode *)malloc(sizeof(OLNode));
        if (p == NULL)
        {
            exit(OVERFLOW);
        }

        if (readFromConsole)
        {
            printf("第%2d组：", k);
            scanf("%d%d%d", &i, &j, &(p->e));
        }
        else
        {
            ReadData(fp, "%d%d%d", &i, &j, &(p->e));
        }

        p->i = i; // 行号
        p->j = j; // 列号
        p->right = p->down = NULL;

        /*
         * 开始行的插入
         */

        // 如果该行还没有元素，或已有元素均位于该元素右侧，则可以直接插入
        if ((*M).rhead[i] == NULL || (*M).rhead[i]->j > j)
        {
            // 定位行表中的插入位置
            p->right = (*M).rhead[i];
            (*M).rhead[i] = p;
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

/*
 * 销毁稀疏矩阵
 */
int DestroySMatrix(CrossList *M)
{
    int i;
    OLNode *p, *q;

    // 无论从按行还是按列，只需要朝着一个方向去遍历销毁就可以了
    for (i = 1; i <= (*M).mu; ++i)
    {
        p = (*M).rhead[i];
        while (p != NULL)
        {
            q = p;
            p = p->right;
            free(q);
        }
    }

    free((*M).rhead);
    free((*M).chead);

    (*M).rhead = (*M).chead = NULL;
    (*M).mu = (*M).nu = (*M).tu = 0;

    return OK;
}