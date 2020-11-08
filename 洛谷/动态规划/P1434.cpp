//分类隶属于矩形dp，是完美的实践了记忆化搜索的一道题，难度不大
#include <bits/stdc++.h>
using namespace std;
const int N = 120;
int C, R, ans, f[N][N], a[N][N]; //CR分别为列数行数，ans为答案，f为记忆数组，a为原始数据数组
const int u[4] = {0, 0, 1, -1};  //注意这种新写法，u,v数组组合起来分别对应四个方向，方便用循环去控制遍历上下左右。
const int v[4] = {-1, 1, 0, 0};
int dp(int x, int y)
{
    if (x < 1 || y < 1 || x > R || y > C) //递归终点，返回0即可，这样正好不影响结果又进行了返回操作。
                                          //这里尤其注意别tmd把行列弄混，真的艹了
    {
        return 0;
    }
    if (f[x][y]) //如果已经访问过了直接返回
    {
        return f[x][y];
    }
    f[x][y] = 1; //未访问过情况下初始化f数组为1因为此题计量单位就是1，代表走了一步
    for (int i = 0; i <= 3; i++)
    {
        if (a[x][y] > a[x + u[i]][y + v[i]])
        {
            f[x][y] = max(f[x][y], dp(x + u[i], y + v[i]) + 1);
        }
    }
    return f[x][y];
}
int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            ans = max(ans, dp(i, j)); //这里将每一个点都当做起点去dp一遍来找到最大值
        }
    }
    cout << ans;
    return 0;
}
