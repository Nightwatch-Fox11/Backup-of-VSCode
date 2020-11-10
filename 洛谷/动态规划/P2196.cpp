//本题采用了逆推的dp，还可以使用记忆化数组和正推，图论，搜索做。
#include <bits/stdc++.h>
using namespace std;
int N, a[25][25], w[25], f[25], nxt[25]; //a数组存邻接矩阵，w[i]是每个地窖中的地雷个数，f[i]表示第i个地窖能挖的最大地雷数，nxt[i]表示路径上i的下一个
int main()                               //这里逆推所以是nxt数组，否则正推是pre数组
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i];
        f[i] = w[i]; //初始化时个地窖能挖的最大地雷数就是每个地窖中的地雷个数
    }
    for (int i = 1; i < N; i++) //初始化邻接矩阵
    {
        for (int j = i + 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = N - 1; i >= 1; i--) //已知f[N]=w[N]，于是少了一重循环;这里体现了本题逆推的思想，从后往前循环
    {
        int maxx = 0, k = 0; //maxx是i号之后所有邻接点中最大的f[i]值，k为其对应点
        for (int j = i + 1; j <= N; j++)
        {
            if (f[j] > maxx && a[i][j])
            {
                maxx = f[j];
                k = j;
            }
        }
        f[i] = maxx + w[i];
        nxt[i] = k;
    }
    int x = 1;
    for (int i = 2; i <= N; i++)
    {
        if (f[i] > f[x])
        {
            x = i;
        }
    }
    cout << x;
    int ans = f[x];
    while (nxt[x])
    {
        cout << ' ' << nxt[x];
        x = nxt[x];
    }
    cout << endl;
    cout << ans;
    return 0;
}