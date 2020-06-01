//线段树模板题  线段树可以在O(nlogn)的时间复杂度内实现单点修改、区间修改、区间查询（区间求和，求区间最大值，求区间最小值）等操作。
#include <bits/stdc++.h>
using namespace std;
long long a[100001], d[270000], b[270000]; //d为线段树数组，b为懒惰标记数组
//数组的大小一般就2^(log2(n)+1)  log2(n)向上取整！！！！！！
long long k, n, temp, t1, t2, k1;
void build(long long l, long long r, long long p) //建树
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }
    long long m = ((l + r) >> 1);
    build(l, m, p << 1),
        build(m + 1, r, (p << 1) | 1);
    d[p] = d[p << 1] + d[(p << 1) | 1];
}
/*   此版本为没有update函数的任意区间求和
long long gsum(long long l, long long r, long long s, long long t, long long p) //l~r为查询区间，s~t为当前区间，p为当前节点  
{
    if (s >= l && t <= r)
    {
        return d[p];
    }
    long long m = (t + s) >> 1;
    long long sum = 0; //注：除以2的位运算写法
    if (m >= l)
    {
        sum += gsum(l, r, l, m, p << 1); //如果左儿子代表的区间 [l,m] 与询问区间有交集,则递归查询左儿子
    }
    if (m < s)
    {
        sum += gsum(l, r, m + 1, s, (p << 1) + 1); // 如果右儿子代表的区间 [m+1,r] 与询问区间有交集,则递归查询右儿子
    }
    return sum;
}
*/
long long gsum(long long l, long long r, long long s, long long t, long long p) //l~r为查询区间，s~t为当前区间，p为当前节点
{
    if (s >= l && t <= r)
    {
        return d[p];
    }
    long long m = (t + s) >> 1; //注：除以2的位运算写法
    if (b[p])                   // 当前节点的懒标记非空,才更新当前节点两个子节点的值和懒标记值
    {
        d[p << 1] += (m - s + 1) * b[p];
        d[(p << 1) | 1] += (t - m) * b[p];
        b[p << 1] += b[p];
        b[(p << 1) | 1] += b[p];
        b[p] = 0;
    }
    long long sum = 0;
    if (m >= l)
    {
        sum += gsum(l, r, s, m, p << 1); //如果左儿子代表的区间 [l,m] 与询问区间有交集,则递归查询左儿子
    }
    if (m < r)
    {
        sum += gsum(l, r, m + 1, t, (p << 1) + 1); // 如果右儿子代表的区间 [m+1,r] 与询问区间有交集,则递归查询右儿子
    }
    return sum;
}
void update(long long l, long long r, long long s, long long t, long long c, long long p) //c为区间内“每个”数都要加上的值,剩下的定义同上
{
    if (l <= s && r >= t) // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }
    long long m = (s + t) >> 1;
    if (b[p] && s != t) // 当前节点的懒标记非空,才更新当前节点两个子节点的值和懒标记值
    {
        d[p << 1] += (m - s + 1) * b[p];
        d[(p << 1) | 1] += (t - m) * b[p];
        b[p << 1] += b[p];
        b[(p << 1) | 1] += b[p];
        b[p] = 0;
    }
    if (l <= m)
    {
        update(l, r, s, m, c, p << 1);
    }
    if (m < r)
    {
        update(l, r, m + 1, t, c, (p << 1) | 1);
    }
    d[p] = d[p << 1] + d[(p << 1) | 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n;
    for (long long i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    build(1, k, 1);
    while (n--)
    {
        cin >> temp >> t1 >> t2;
        if (temp == 1)
        {
            cin >> k1;
            update(t1, t2, 1, k, k1, 1);
        }
        else
        {
            cout << gsum(t1, t2, 1, k, 1) << endl;
        }
    }

    return 0;
}