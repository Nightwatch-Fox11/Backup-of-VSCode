//LCA模板题,共有三种思路（暴力不算），首先是倍增法，算是暴力的改进。然后是RMQ，然后是tarjan，第一种倍增是老师的写法，还有一种倍增增加了lg2数组的预处理，然后在LCA函数的循环中略有不同
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 100;
//链式前向星存图
struct edge
{
    int to, next;
} e[MAXN << 1];      //因为是树，所以有n个节点就有n-1条边，而且树是无向图双向边，这里设为MAXN*2
int head[MAXN], cnt; //老规矩cnt为边序号
void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].next = head[x];
    head[x] = cnt;
}
//log2(MAXN) = 18.9， 所以anc数组定义一个22
int de[MAXN], anc[MAXN][22]; //de[i]为i节点的深度， anc[x][y]为x节点向上走2^(y)后的节点
//倍增要点是预处理，预处理的结果就是anc数组，anc数组就是每个节点走1，2，...步后的节点
void dfs(int x, int fa) //x为树的根结点，fa为x的父亲节点
{
    de[x] = de[fa] + 1; //从树形结构来看，x在下，fa在上，从上往下递推来预处理初始化
    anc[x][0] = fa;
    for (int i = 1; i < 22; i++)
    {
        anc[x][i] = anc[anc[x][i - 1]][i - 1]; //这个状态转移方程是算法的核心之一:意思是x的2^i祖先等于x的2^(i-1)祖先的2^(i-1)祖先, 2^i = 2^(i-1) + 2^(i-1)
    }
    for (int i = head[x]; i; i = e[i].next)
    {
        if (e[i].to != fa) //因为要向下走，防止返回到父节点(往回走)
        {
            dfs(e[i].to, x); //递归过程继续更新anc
        }
    }
}
int LCA(int x, int y)
{
    if (de[x] < de[y]) //不妨设x的深度 >= y的深度
    {
        swap(x, y);
    }
    for (int i = 21; ~i; i--) //i初值足够大，慢慢往小试，值得注意的是i可以取到零而且大概率取到零也就是向上走一步，
    {
        if (de[anc[x][i]] >= de[y]) //跳后深度仍不超过y的深度就继续跳
        {
            x = anc[x][i];
        }
    } //这个循环一定可以保证最后x，y的深度是相同的。
    if (x == y)
    {
        return x;
    }
    for (int i = 21; ~i; i--)
    {
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i];
            y = anc[y][i];
        }
    } //此循环便是让x，y一起向上跳，跳出循环时x，y已经成为lca的两个儿子节点了，也就是x，y的父亲就是答案
    return anc[x][0];
}
int N, M, S, t1, t2;

int main()
{
    scanf("%d %d %d", &N, &M, &S);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &t1, &t2);
        add(t1, t2);
        add(t2, t1);
    }
    dfs(S, 0);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &t1, &t2);

        printf("%d\n", LCA(t1, t2));
    }

    return 0;
}