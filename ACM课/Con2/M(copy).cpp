// 一
/*
首先，这个矩阵肯定只能是1和-1组成的矩阵了
若k为1，那么每一列只能有偶数个-1；若k为-1，那么每一列只能有奇数个-1
那么对于每一列（长度为N），都有2^(N−1)种可能的选择
那么，假设前M−1列都构造完毕，最后一列呢？
显然，如果第1行已经有x个-1，那么最后一列的第1行应该是一个使得该行有奇数个-1(对应k=-1)/偶数个-1(对应k=1)的数，显然也可以确定
这样，整个矩阵都可以构建完成，可见这个矩阵的确定只与前M-1列有关，一共有 (2^(N−1))^(M−1)个矩阵
那么问题来了：N行的乘积为k了，前M-1列的乘积也为k了，那么第M列的乘积呢？
讨论如下：
k=1：若前M-1列构成的矩阵第i行乘积为-1，那么第M列第i行也是-1；若为1，那么第i行也是1；
既然如此，那么说明第M列元素的乘积等于前M-1列的所有行的乘积，后者等价于所有列的乘积，故第M列的乘积为1
k=-1：若前M-1列构成的矩阵第i行乘积为-1，那么第M列第i行是1；若为1，那么第i行是-1；
既然如此，那么说明第M列元素的乘积等于前M-1列的所有 [行的乘积的相反数]
的乘积，后者等于所有数的乘积再乘以(−1)^N（N为行数），等价于前M-1列的乘积乘上(−1)^N，也就是说最后一列的乘积为(−1)^M−1×(−1)^N
若N×(M−1)为偶数，最后一列乘积为1
若N×(M−1)为奇数，最后一列乘积为-1
其余结论显然
*/
//WA
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll m, n;
ll quickPow(ll k)
{
    ll ans = 1, now = 2;
    while (k)
    {
        if (k & 1)
            ans *= now, ans %= MOD;
        now *= now, now %= MOD;
        k >>= 1;
    }
    return ans;
}

int main()
{
    int k;
    cin >> m >> n >> k;
    if (k == -1 && (m + n) % 2)
    {
        cout << "0" << endl;
        return 0;
    }
    m--, n--;
    m %= (MOD - 1);
    n %= (MOD - 1);
    ll t = m * n % (MOD - 1);
    cout << quickPow(t) << endl;
    return 0;
}
// 二 暴力
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll m, n;
ll quickPow(ll k)
{
    ll ans = 1, now = 2;
    while (k)
    {
        if (k & 1)
            ans *= now, ans %= MOD;
        now *= now, now %= MOD;
        k >>= 1;
    }
    return ans;
}

int main()
{
    int k;
    cin >> m >> n >> k;
    if (k == -1 && (m + n) % 2)
    {
        cout << "0" << endl;
        return 0;
    }
    m--, n--;
    m %= (MOD - 1);
    n %= (MOD - 1);
    ll t = m * n % (MOD - 1);
    cout << quickPow(t) << endl;
    return 0;
}
// 三
/*当K=1时
先随便写出一个(N-1)*(M-1)的元素为1或-1的矩阵
对第i(1<=i<=N-1)行进行分类讨论
如果第i行里第1列到M-1列的元素之积为1，则在第N行第M列里填充1，则显然会使得第i行从第1列到第M列的元素之积为1，
如果第i行里第1列到M-1列的元素之积为-1，则在第N行第M列里填充-1，则显然会使得第i行从第1列到第M列的元素之积也为1，
也就是说令
对第j(1<=J<=M-1)列也这样处理，即令
这样分别处理完以后就可以保证第1行到第N-1行的各行内元素之积一定为1且第1行到第N-1列的各列内元素之积也一定为1，
那么只要使得第N行和第M列的元素之积为1就可以了。
因为矩阵A的元素 ,
那么可以得到和，容易得到，也就是说不论在第N行第M列里填充1或者-1，都会使得第N行和第M列内各元素之积相等，
所以，只要令就可以使得这个矩阵满足条件了。
而且，显然可以的知道不论一个什么样的(N-1)*(M-1)的矩阵都有且只有一个满足K=1的条件的N*M的矩阵与之对应，
也就是说当K=1时，答案就是
当K=-1的时候，方法与k=1的时候类似，
但是当N和M的奇偶性不一样的时候就会使得不论一个什么样的(N-1)*(M-1)的矩阵都不会存在一个与之对应的符合条件的N*M的矩阵。因为此时 ,而
不论在第N行第M列里填充1或者-1，都会使得第N行和第M列内各元素之积都不 相等。
所以当K=-1且N,M的奇偶性相同时，答案就是，否则是0。
*/
// AC
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;

int n, m, k;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if ((k == 1) || ((k == -1) && ((n + m) % 2 == 0)))
    {
        long long ans = 1;
        for (int i = 1; i <= n - 1; i++)
            for (int j = 1; j <= m - 1; j++)
                ans = ans * 2ll;
        cout << ans << endl;
    }
    else
        puts("0");
    return 0;
}
