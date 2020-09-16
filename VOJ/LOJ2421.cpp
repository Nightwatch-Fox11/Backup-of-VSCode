//本题有两种做法，并查集或者tarjin。本质都是求图中最小环（本题中的强连通分量）
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10; //图中最大点数

void in(int &read) //读入优化函数
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    read = x;
}
//存储图的数据结构--链式前向星
//也可以使用vector，好像这道题更简单
int head[MAXN]; //head[i]数组，表示以 i 为起点的最后一条边的编号
struct edge
{
    int to, next; //next表示与这个边起点相同的上一条边的编号。 to表示当前边的终点
} e[MAXN];

int cnt;                      //边序号
inline void add(int x, int y) //向图中添加边的函数
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
//tarjin
int dfn[MAXN], low[MAXN], indexx, top, instk[MAXN], stk[MAXN], ans = 0x7ffffff / 3, t, n, sa; //index为时间戳指针，每次加一。top为栈顶指针。stk为栈，instk判断是否在栈中
                                                                                              //也有人用STL stack实现栈，稍后添加此种做法
                                                                                              //t为add函数的临时变量，sa为某个连通分量中的节点数， n节点数
                                                                                              //值得注意的是ans，初值设为一个极大的变量，因为每次low[u] == dfn[u]的时候（也就是遇到了一个新的强连通分支时）
                                                                                              //都有可能更新ans的值，找的就是最小环。
void tarjan(int u)
{
    dfn[u] = low[u] = ++indexx; //将u压入栈
    instk[u] = 1;
    stk[++top] = u;
    for (int i = head[u]; i; i = e[i].next) //遍历u的所有邻接边
    {
        if (!dfn[e[i].to]) //如果是树边
        {
            tarjan(e[i].to);                    //继续深入，相当于dfs
            low[u] = min(low[u], low[e[i].to]); //回归时更新low值，因为是回归时所以是两个low比较
        }
        else if (instk[u]) //如果是后向边，不过这里不确定是instk[u]还是instk[e[i].to]
        {
            low[u] = min(low[u], dfn[e[i].to]); //直接比较子节点的dfn和自己的low来更新
        }
        if (low[u] == dfn[u]) //遇到了强连通
        {
            sa = 0;
            do
            {
                sa++;
                instk[stk[top--]] = 0;
            } while (u != stk[top + 1]);
            if (sa > 1)
            {
                ans = min(sa, ans);
            }
        }
    }
}

int main()
{
    in(n);
    for (int i = 1; i <= n; i++)
    {
        in(t);
        add(i, t);
    }
    for (int i = 1; i <= n; i++)
    {
        tarjan(i);
    }
    cout << ans << endl;
    return 0;
}
//通过本题也就是熟悉了tarjin最基础的应用，后续会补充并查集算法，以及vector+stack版本