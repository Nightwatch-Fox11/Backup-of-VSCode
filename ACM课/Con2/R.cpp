#include <bits/stdc++.h>
using namespace std;
int dat[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> dat[i];
    }
    sort(dat, dat + n);
    while (m--)
    {
        int k;
        cin >> k;
        int wh = lower_bound(dat, dat + n, k) - dat;
        cout << n - wh << endl;
    }
    return 0;
}
