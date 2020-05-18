//洛谷P2871 [USACO07DEC]Charm Bracelet S
#include <bits/stdc++.h>
using namespace std;
int N, M; /*N件物品 & 背包容量M*/
int w[12881], v[12881], f[12881];
int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= w[i]; j--)
        {
            if (f[j - w[i]] + v[i] > f[j])
            {
                f[j] = f[j - w[i]] + v[i];
            }
        }
    }
    cout << f[M];

    return 0;
}