#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 4, MAXM = 5e4 + 4, inf = 1 << 16;
int cnt, head[MAXN], p[MAXN];              //前两个是链式前向星参数，p数组为并查集父亲数组
int de[MAXN], anc[MAXN][21], dp[MAXN][21]; //这里的dp数组是一个动态规划的优化，dp[k][i]指节点k和节点p[k][i]之间路径中具有最小权值的边的权值
int n, m;                                  //点，边
struct edge1                               //记录原题的输入，用于Kruskal建树
{
    int x, y, dis; //分别是边的两个节点以及限重dis
} e1[MAXM];
struct edge2 //链式前向星，用于LCA
{
    int to, next, val;
} e2[MAXM * 2];
void add(int x, int y, int z)
{
    e2[++cnt].to = y;
    e2[cnt].next = head[x];
    head[x] = cnt;
    e2[cnt].val = z;
}
bool cmp(const edge1 &a, const edge1 &b)
{
    return a.dis > b.dis;
}
int find(int x)
{
    return x == find(x) ? x : p[x] = find(p[x]);
}
void dfs(int x, int fa)
{
    for (int i = 1; (1 << i) < de[x]; i++)
    {
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
        dp[x][i] = min(dp[x][i - 1], dp[anc[x][i - 1]][i - 1]);
    }
    for (int i = head[x]; i; i = e2[i].next)
    {
        if (e2[i].to != fa)
        {
            de[e2[i].to] = de[x] + 1;
            anc[e2[i].to][0] = x;
            dp[e2[i].to][0] = e2[i].val;
            dfs(e2[i].to, x);
        }
    }
}
int query(int x, int y)
{
    if (de[x] < de[y])
    {
        swap(x, y);
    }
    int res = de[x] - de[y], ret = inf; //ret记录最小边权，因此初值设为很大
    for (int i = 20; ~i; i--)
    {
        if ((res >> i) & 1) //
        {
            ret = min(ret, dp[x][i]);
            x = anc[x][i];
        }
    }
    if (x == y)
    {
        return ret;
    }
    for (int i = 20; ~i; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            ret = min(ret, min(dp[x][i], dp[y][i]));
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return min(ret, min(dp[x][0], dp[y][0]));
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &e1[i].x, &e1[i].y, &e1[i].dis);
    }
    sort(e1 + 1, e1 + 1 + m, cmp);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x = find(e1[i].x), y = find(e1[i].y);
        if (x == y)
        {
            continue;
        }
        add(x, y, e1[i].dis);
        add(y, x, e1[i].dis);
        p[x] = y;
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            dfs(i, 0);
        }
    }
    int q, t1, t2;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &t1, &t2);
        if (find(t1) != find(t2))
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n", query(t1, t2));
    }

    return 0;
}