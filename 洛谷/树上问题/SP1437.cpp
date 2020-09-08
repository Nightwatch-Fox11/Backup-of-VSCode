//树的直径模板题，思路是采用两次dfs，第一次随便从一个结点出发（本题选第一个点），到达最远点，然后从最远点开始第二次dfs，
//此次所能到达的最长路径即为树的直径， 要特别注意本题中dfs的写法，具有规律性，属于链式前向星形式的dfs。
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
int n, cnt, head[MAXN], dis[MAXN];
struct edge
{
    int to, next;
} e[MAXN * 2];

void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}

void dfs(int x, int step)
{
    if (dis[x])
    {
        return;
    }
    dis[x] = step;
    for (int i = head[x]; i; i = e[i].next)
    {
        dfs(e[i].to, step + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        add(t1, t2);
        add(t2, t1);
    }
    dfs(1, 1);
    int maxn = 0, k;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxn)
        {
            maxn = dis[i];
            k = i;
        }
    }
    maxn = 0;
    memset(dis, 0, sizeof(dis));
    dfs(k, 1);
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxn)
        {
            maxn = dis[i];
        }
    }
    printf("%d", maxn - 1);

    return 0;
}
