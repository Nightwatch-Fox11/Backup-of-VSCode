#include <bits/stdc++.h>
using namespace std;
int mapp[2001][2001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        mapp[x][y] = 1;
        mapp[y][x] = 1;
    }
    return 0;
}