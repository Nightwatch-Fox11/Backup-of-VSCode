/*原问题具体见https://www.cnblogs.com/tgycoder/p/4980655.html*/
//简述：给定一根长度为n英寸的长钢条，求最优切割方案，使得销售收益最大。注意，最优方案也有可能是完全不用切割。
//共有2^(n-1)种方案，纯暴力O(2^n),因此dp    tag : 记忆化搜索
//每次切割考虑切点两部分的最大价值,或者不切
#include <bits/stdc++.h>
using namespace std;
int v[1001], r[1001];           //r为记忆数组
int dp(int v[], int r[], int n) //自顶而下的记忆化搜索
{
    if (r[n] > 0)
    {
        return r[n];
    }
    int profit = 0;
    for (int i = 1; i <= n; i++)
    {
        profit = max(profit, dp(v, r, n - i) + v[i]); //状态转移方程
    }
    return r[n] = profit;
}
//自下而上递推法
int dp2(int v[], int r[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int profit = v[i];
        for (int j = 1; j <= i / 2; j++) //等式Rn = max(pn,r1+rn-1,r2+rn-2,…,rn-1+r1)，可以看出,r1+rn-1和rn-1+r1其实是一样的。所以没有必要循环到i,截至到i/2即可。
            profit = max(profit, r[j] + r[i - j]);
        r[i] = profit;
    }
    return r[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cout << dp(v, r, n);

    return 0;
}