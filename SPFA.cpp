//暂定为SPFA模板
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8 - 1;
struct edge
{
    int v, w;
};
vector<vector<edge>> a;       //相当于邻接表
void add(int u, int v, int w) //注意这种新的形式的添加函数
{
    edge temp;
    temp.v = v;
    temp.w = w;
    a[u].push_back(temp);
}
int n, m, t1, t2, t3;
int main()
{
    scanf("%d %d", &n, &m);
    a.resize(n); //注意这里用法
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &t1, &t2, &t3);
        add(t1, t2, t3);
    }
    vector<int> dis(n, INF);
    vector<bool> flag(n, false);
    queue<int> q;
    q.push(0); //数组下标从0开始记
    flag[0] = true;
    dis[0] = 0;
    while (!q.empty())
    {
        t1 = q.front();
        q.pop();
        flag[t1] = false;
        for (int i = 0; i < a[t1].size(); i++)
        {
            if (dis[a[t1][i].v > dis[t1] + a[t1][i].w])
            {
                dis[a[t1][i].v = dis[t1] + a[t1][i].w];
                if (!flag[a[t1][i].v])
                {
                    q.push(a[t1][i].v);
                    flag[a[t1][i].v] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dis[i] << ' ';
    }

    return 0;
}
