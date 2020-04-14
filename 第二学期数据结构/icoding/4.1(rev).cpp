#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"
#define MAXSIZE 100 //假设非零元个数的最大值为100
typedef struct
{
    int i, j;   //非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e; //非零元的值
} Triple;

typedef struct
{
    Triple data[MAXSIZE]; // 非零元三元组表
    int m, n, len;        // 矩阵的行数、列数和非零元个数
} TSMatrix;
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ)
{
    int m, n, k;
    if (pM->m != pN->m || pM->n != pN->n)
    {
        return 0;
    }
    pQ->m = pM->m;
    pQ->n = pM->n;
    pQ->len = 0;
    m = n = k = 0;
    while (m < pM->len && n < pN->len)
    {
        if (pM->data[m].i < pN->data[n].i)
        {
            pQ->data[k] = pM->data[m];
            m++;
        }
        else if (pM->data[m].i > pN->data[n].i)
        {
            pQ->data[k] = pN->data[n];
            n++;
        }
        else
        {
            if (pM->data[m].j < pN->data[n].j)
            {
                pQ->data[k] = pM->data[m];
                m++;
            }
            else if (pM->data[m].j > pN->data[n].j)
            {
                pQ->data[k] = pN->data[n];
                n++;
            }
            else
            {
                if (pM->data[m].e + pN->data[n].e)
                {
                    pQ->data[k].i = pM->data[m].i;
                    pQ->data[k].j = pM->data[m].j;
                    pQ->data[k].e = pM->data[m].e + pN->data[n].e;
                    n++;
                    m++;
                }
                else
                {
                    m++;
                    n++;
                    continue;
                }
            }
        }
        k++;
        pQ->len++;
    }
    while (m < pM->len)
    {
        pQ->data[k] = pM->data[m];
        m++;
        k++;
        pQ->len++;
    }
    while (n < pN->len)
    {
        pQ->data[k] = pN->data[n];
        n++;
        k++;
        pQ->len++;
    }
    return 1;
}
