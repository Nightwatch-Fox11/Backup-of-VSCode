#include <bits/stdc++.h> //Prim
using namespace std;
int N, M;                                          //点，边
const int MAXN = 5e3 + 100;                        //也可以采用链式前向星存
int graph[MAXN][MAXN], dis[MAXN], ans, t1, t2, t3; //prim算法使用邻接矩阵存图，重点是 dis[i]用来表示已经加入的点集到节点i的最小值
bool vis[MAXN];                                    //vis[i] = true代表节点已被访问过
int main()
{
    scanf("%d %d", &N, &M);
    memset(graph, 0x7f, sizeof(graph)); //将邻接矩阵初值设为无穷大 代表初始不连通
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < M; i++) //读入
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        if (t1 == t2 || t3 >= graph[t1][t2]) //要特别注意的是采用临接矩阵时要特殊考虑主对角线以及重边的问题
        {
            continue;
        }

        graph[t1][t2] = graph[t2][t1] = t3;
    }
    for (int i = 1; i <= N; i++) //初始化dis数组，也就是初始时点集只有1号点，到剩下任意一点的最小距离均为无穷大
    {
        dis[i] = graph[1][i];
    }
    vis[1] = true;
    dis[N + 1] = 0x7fffffff;        //只有N个节点，但是设一个N+1节点设为无穷大作为监视哨
    for (int i = 0; i < N - 1; i++) //生成树共有N-1条边，每次加一条边，所以共循环N-1次
    {
        int k = N + 1; //k初值相当于无穷远点
        for (int j = 1; j <= N; j++)
        {
            if (vis[j])
            {
                continue;
            }
            if (dis[j] < dis[k]) //不断寻找最小权点，并将k点更新为最小权点
            {
                k = j;
            }
        }
        ans += dis[k];
        vis[k] = true;
        for (int j = 1; j <= N; j++)
        {
            if (graph[k][j] < dis[j])
            {
                dis[j] = graph[k][j];
            }
        } //每次加入一个新点时都要重新更新dis数组
    }
    printf("%d", ans);
    return 0;
}