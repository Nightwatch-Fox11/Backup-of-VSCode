/*
把城市数目n当做为点数，n*k为总点数，则每条铁路消耗两个点数；
总共可以建n*k/2条铁路；
特殊情况：
1.城市数n为1，ans=0
2.单城可修铁路数k为0， ans=0
3.单城仅可修1条铁路且城市数大于2， ans=0
4.单城可修铁路数k 大于等于 n-1，任意两个城市都能联通， ans=n(n-1)/2
5.单城可修铁路数k 小于 n-1，每座城市都修满k条铁路 ans = n*k/2
*/
#include <iostream>
using namespace std;
int main()
{
    int T, n, k;
    cin >> T;
    int ans;
    while (T--)
    {
        cin >> n >> k;
        if (n == 1 || k == 0 || (n != 2 && k == 1))
            ans = 0;
        else if (k > n - 1)
            ans = n * (n - 1) / 2;
        else
            ans = n * k / 2;
        cout << ans << endl;
    }
    return 0;
}
