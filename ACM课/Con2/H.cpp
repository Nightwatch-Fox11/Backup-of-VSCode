#include <bits/stdc++.h>
using namespace std;
string a;
int m[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(m, 0, sizeof(m));
    int x, y, t;
    cin >> x >> y >> a;
    for (auto c : a)
    {
        switch (c)
        {
        case 'L':
            m[0]++;
            break;
        case 'R':
            m[1]++;
            break;
        case 'U':
            m[2]++;
            break;
        case 'D':
            m[3]++;
            break;
        }
    }
    if

        return 0;
}