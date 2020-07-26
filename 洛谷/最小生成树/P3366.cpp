#include <bits/stdc++.h>
using namespace std;
int N, M; //点，边
const int MAXN = 5e3 + 100;
const int MAXM = 2e5 + 100;
struct edge //注意这里用邻接表or邻接矩阵都不合适，所以选取这种特制的结构存图
{
    int fr, to, val; //起点，终点，权值（不过本题中起点终点没有差别，因为是无向图）
} e[MAXM];
int p[MAXN];
int find(int x) //经典并查集函数
{
    return x == p[x] ? x : (p[x] = find(p[x]));
}
bool cmp(const edge &p1, const edge &p2)
{
    return p1.val < p2.val;
}
int main() //法一Kruskal算法
{
    scanf("%d %d", &N, &M);
    int i, sum = 0, cnt = 0, t1 = 0, t2 = 0; //sum为当前权值和，cnt为边计数器(代表已选的边数)
    for (i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &e[i].fr, &e[i].to, &e[i].val);
    }
    for (i = 1; i <= N; i++)
    {
        p[i] = i;
    }
    sort(e, e + M, cmp); //将边根据权值排序
    for (int i = 1; i <= M; i++)
    {
        t1 = find(e[i].fr);
        t2 = find(e[i].to);
        if (t1 != t2) //也就是新加入边后不形成回路
        {
            sum += e[i].val;
            p[t1] = t2;
            cnt++;
            if (cnt >= N - 1) //也就是已经包含了所有的点了(同时边也够了)
            {
                break;
            }
        }
    }
    printf("%d", sum);
    return 0;
}