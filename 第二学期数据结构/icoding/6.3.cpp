#include <stdio.h>
#include "graph.h" //请勿删除，否则检查不通过

typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr info;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode firstarc;
} VNode;
typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v)    //删除顶点 v
{
    int V = locate_vertex(G, v), i = 0;
    if (V == -1)
    {
        return false;
    }
    VNode *vv = &(G->vertex[V]);
    ArcNode *vvv = &(vv->firstarc);

    while (vvv->nextarc != NULL)
    {
        i++;
        ArcNode *prev = vvv;
        vvv = vvv->nextarc;
        free(prev);
    }
    free(vvv);
    free(vv);
    G->vexnum--;
    G->arcnum -= i;
    return true;
}
