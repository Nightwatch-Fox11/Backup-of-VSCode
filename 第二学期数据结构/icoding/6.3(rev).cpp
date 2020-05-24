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
    int V = locate_vertex(G, v), i;
    if (V == -1)
    {
        return false;
    }
    while (G->vertex[V].firstarc)
    {
        ArcNode *P = G->vertex[V].firstarc;
        if (P->nextarc)
        { //先free表头结点后面的
            ArcNode *temp = P->nextarc;
            P->nextarc = temp->nextarc;
            free(temp);
        }
        else
        {
            free(P); //free表头结点
            G->vertex[V].firstarc = NULL;
        }
        G->arcnum--; //边的数量-1
    }
    G->vexnum--; //结点的数量-1
    for (i = V; i < G->vexnum; i++)
    { //表头结点中，后面的向前移动
        G->vertex[i] = G->vertex[i + 1];
    }

    for (i = 0; i < G->vexnum; i++)
    {
        ArcNode *P = G->vertex[i].firstarc, *pNode = NULL;
        ArcNode *temp; //存储要被删掉的结点
        while (P)
        {
            if (V == P->adjvex)
            { //P的下个结点是V
                if (!pNode)
                { //P是表头结点
                    temp = G->vertex[i].firstarc;
                    G->vertex[i].firstarc = P->nextarc;
                }
                else
                {
                    pNode->nextarc = P->nextarc;
                    temp = P;
                }
                P = P->nextarc;
                free(temp);
                G->arcnum--;
            }
            else
            {
                pNode = P;
                P = P->nextarc;
            }
        }
    }
    return true;
}
