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