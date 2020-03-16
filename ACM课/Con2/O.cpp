#include <bits/stdc++.h>
using namespace std;
int m[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(m, 0, sizeof(m));
    int L, n, cns = 0;
    cin >> L >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i <= b; i++)
        {
            m[i] = 1;
        }
    }
    for (int i = 0; i <= L; i++)
    {
        if (!m[i])
        {
            cns++;
        }
    }
    cout << cns;
    return 0;
}