//本题注意map的嵌套使用，因为直接开二维数组要10^5*10^5而题目中说最多也就10^7所以会mle，而map的话复杂度logn，应付10^7是可以的。
#include <bits/stdc++.h>
using namespace std;
map<int, map<int, int>> a;
int n, q, t0, t1, t2, t3;
int main()
{
    cin >> n >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t0 >> t1 >> t2;
        if (t0 == 1)
        {
            cin >> t3;
            a[t1][t2] = t3;
        }
        else
        {
            cout << a[t1][t2] << endl;
        }
    }

    return 0;
}