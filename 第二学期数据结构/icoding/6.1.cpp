#include <stdio.h>
#include "graph.h" // 请不要删除，否则检查不通过
typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct
{
    VertexType vertex[MAX_VERTEX_NUM];        //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;                       //图的当前顶点数和弧数
    GraphType type;                           //图的种类标志
} MatrixGraph;

int matrix_locate_vertex(MatrixGraph MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1

bool matrix_insert_vertex(MatrixGraph *G, VertexType v)
{

    if (matrix_locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM) //这sb题的第一个坑是 G->vexnum + 1 >= MAX_VERTEX_NUM
    {
        return false;
    }
    G->vertex[G->vexnum] = v;
    G->vexnum++;
    for (int i = 0; i < G->vexnum; i++) //这是第二个坑
        G->arcs[i][G->vexnum - 1] = G->arcs[G->vexnum - 1][i] = 0;
    return true;
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w)
{
    int V = matrix_locate_vertex(G, v), W = matrix_locate_vertex(G, w);
    if (W == -1 || V == -1)
    {
        return false;
    }
    if (G->type == DG)
    {
        if (G->arcs[V][W])
        {
            return false;
        }
        G->arcs[V][W] = 1;
    }
    else
    {
        if (G->arcs[V][W] || G->arcs[W][V])
        {
            return false;
        }
        G->arcs[V][W] = G->arcs[W][V] = 1;
    }
    G->arcnum++;
    return true;
}