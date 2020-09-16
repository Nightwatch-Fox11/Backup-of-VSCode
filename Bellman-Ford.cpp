//暂定为Bellman-Ford 模板
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
const int INF = 1e8 - 1;
struct edge
{
    int u, v, w;
} e[N];
int n, m, dis[N];
bool flag;
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) //边号从0开始
    {
        dis[i] = INF;
    }
    dis[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        flag = false;
        for (int j = 0; j < m; j++)
        {
            if (dis[e[j].v] > dis[e[j].u] + e[j].w)
            {
                dis[e[j].v] = dis[e[j].u] + e[j].w;
                flag = true;
            }
        }
        if (!flag) //进行了一轮循环后没更新证明已经找到了最短路
        {
            break;
        }
    }
    flag = false;
    for (int j = 0; j < m; j++)
    {
        if (dis[e[j].v] > dis[e[j].u] + e[j].w)
        {
            dis[e[j].v] = dis[e[j].u] + e[j].w;
            flag = true;
        }
    }
    if (flag)
    {
        cout << "有负权回路";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", dis[i]);
        }
        }

    return 0;
}