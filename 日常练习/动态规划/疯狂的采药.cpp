#include <bits/stdc++.h>
using namespace std;
int v[100001], w[100001], f[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = w[i]; j <= t; j++) //注意这个和01背包的差距仅有正反序这一行
        {
            if (f[j - w[i]] + v[i] > f[j])
            {
                f[j] = f[j - w[i]] + v[i];
            }
        }
    }
    cout << f[t];
    return 0;
}