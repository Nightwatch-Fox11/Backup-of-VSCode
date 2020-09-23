//迪杰斯特拉模板题
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105, inf = 1e7;
int g[MAXN][MAXN]; //法一，采用邻接矩阵存储
int n, m, t1, t2, t3;
int dis[MAXN], f[MAXN]; //dis[i]为起点到i节点的最短距离， f[i]表是i节点的状态，f[i]=0代表临时标号，f[i]=1代表固定标号

int main()
{
    while (1)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = 0; i < MAXN; i++) //初始化邻接矩阵
        {
            for (int j = 0; j < MAXN; j++)
            {
                if (i == j)
                {
                    g[i][j] = 0;
                }
                else
                {
                    g[i][j] = inf;
                }
            }
        }
        for (int i = 0; i < m; i++) //录入邻接矩阵
        {
            scanf("%d %d %d", &t1, &t2, &t3);
            if (t3 < g[t1][t2]) //防止重边，本题好像没考
            {
                g[t1][t2] = g[t2][t1] = t3;
            }
        }
        for (int i = 2; i <= n; i++) //初始化dis矩阵
        {
            dis[i] = g[1][i];
        }
        memset(f, 0, sizeof(f));
        dis[1] = 0, f[1] = 1;
        for (int i = 0; i < n - 1; i++) //因为一共n-1个临时节点，而更新n-2次后，最后只剩一个节点了，不必再更新了，所以只循环n-2次
        {
            t1 = -1;                     //此时t1表示临时编号中最小的编号
            t2 = inf;                    //此时t2表示临时编号中最小值
            for (int j = 2; j <= n; j++) //不断循环来更新t1 t2，因为1节点必是固定节点，所以从2开始
            {
                if (dis[j] < t2 && f[j] == 0)
                {
                    t2 = dis[j];
                    t1 = j;
                }
            }
            if (t1 == -1) //说明图不连通
            {
                break;
            }
            if (t1 == n) //已找到到终点的最短路
            {
                break;
            }
            f[t1] = 1;
            for (int j = 2; j <= n; j++)
            {
                if (f[j] == 0 && t2 + g[t1][j] < dis[j])
                {
                    dis[j] = t2 + g[t1][j];
                }
            }
        }
        if (dis[n] >= inf)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", dis[n]);
        }
    }

    return 0;
}