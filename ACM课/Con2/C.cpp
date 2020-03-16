//1. 递归
#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL ans = 0;
int n;
int m;
LL dp[100][100];

int main()
{
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        dp[0][i] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
                if (k != j)
                    dp[i][j] += dp[i - 1][k];
        }

    if (m <= 1 || n == 1)
        ans = 0;
    cout << dp[m][1] << endl;
}
// 2.递推    f(m,n)=(m-1)^(n-1)-f(m,n-1)
#include <stdio.h>
#include <stdlib.h>
int my_pow(int x, int t) //(math.h)用里面的pow函数来求幂误差挺大的，小整数的整数次幂比较好算，就自己写了个
{
    int ans = 1;
    for (int i = 1; i <= t; i++)
        ans = x * ans;
    return ans;
}
int solve(int m, int n)
{
    int ans;
    if (n == 1)
        ans = 0;
    else
        ans = my_pow(m - 1, n - 1) - solve(m, n - 1);
    return ans;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", solve(m, n));
    return 0;
}

// 3.公式推倒
#include <iostream>
using namespace std;
int N, M;
int main()
{
    cin >> N >> M;
    int ans = 1;
    for (int i = 1; i <= M; ++i)
        ans *= N - 1;
    if (M & 1)
        ans = (ans - N + 1) / N;
    else
        ans = (ans + N - 1) / N;
    cout << ans;
}
/*结论题：


若M为奇数，则答案为((N-1)^M-N+1)/N
若M为偶数，则答案为((N-1)^M+N-1)/N


证明一：


设F[k]为球最后传给第k个人的情况数
显然球最后传给第2到第N个人的概率相同，即F[2]=F[3]=...=F[N]
F[1]+F[2]+F[3]+...+F[N]=(N-1)^M  即共有(N-1)^M种传球路线
F[1]+(N-1)*F[2]=(N-1)^M
而球一旦传给第3到第N个人，则球最后传给前两个人的概率相同
即在球曾传给第3到第N个人的情况中，最后传给前两个人的情况数相同
而在球没有传给第3到N个人的情况中，即前两个人互传的情况，有：
若M为奇数，则最后传给第2个人
若M为偶数，则最后传给第1个人
即F[2]=F[1]+1(M为奇数)
F[2]=F[1]-1(M为偶数)
综上所述，F[1]=((N-1)^M-N+1)/N(M为奇数)
F[1]=((N-1)^M+N-1)/N(M为偶数)


证明二:


设F[k]为k次传球后传给第1个人的情况数
则F[k]=(N-1)^(k-1)-F[k-1]，且F[1]=0
故若M为奇数，则F[m]=(N-1)^(M-1)-(N-1)^(M-2)+...-(N-1)^1
=(1-N)*((1-N)^(M-1)-1)/(1-N-1)
=((N-1)^M-N+1)/N
若M为偶数，则F[m]=(N-1)^(M-1)-(N-1)^(M-2)+...+(N-1)^1
=(N-1)((N-1)^(M-2)-(N-1)^(M-3)+...-(N-1)^1+1)
=(N-1)(((N-1)^(M-1)-N+1)/N+1)
=((N-1)^M+N-1)/N*/