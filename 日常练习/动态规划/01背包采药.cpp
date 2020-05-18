#include <bits/stdc++.h>
using namespace std;
int T, M, w[1001], v[1001], f[1001];
int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = T; j >= w[i]; j--)
        {
            if (f[j - w[i]] + v[i] > f[j])
            {
                f[j] = f[j - w[i]] + v[i];
            }
        }
    }
    cout << f[T];
    return 0;
}