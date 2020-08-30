//缩点+tarjan 注意树边，前向边，后向边，横叉边区分，后三个属于非树边
#include <bits/stdc++.h>
using namespace std;
int N, M, t1, t2;
const int MAXN = 1e4 + 100;
const int MAXM = 5e4 + 100;
//！！ 新型图论数据结构--链式前向星 ！！
int head[MAXN]; //head[i]数组，表示以 i 为起点的最后一条边的编号
struct edge
{
    int to, next; //next表示与这个边起点相同的上一条边的编号。 to表示当前边的终点
} e[MAXM];
int cnt; //边序号
inline void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}

int dfn[MAXN], low[MAXN], stk[MAXN], instack[MAXN], index, top;
void tarjan(int u)
{
}
int main()
{
    scanf("%d %d", &N, &M);
    while (M--)
    {
        scanf("%d %d", &t1, &t2);
    }

    return 0;
}