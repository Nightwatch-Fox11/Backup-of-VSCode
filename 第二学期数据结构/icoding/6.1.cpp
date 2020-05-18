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
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w)
{
}