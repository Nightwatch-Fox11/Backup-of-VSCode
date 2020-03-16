#include <bits/stdc++.h>
using namespace std;
int m[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {

        memset(m, 0, sizeof(m));
        int a, b, c;
        cin >> a >> b;
        for (int i = 0; i < a; i++)
        {
            cin >> c;
            m[c + 500000]++;
        }
        for (int i = 1000000, t = 0; i >= 0 && t < b;)
        {
            if (m[i])
            {

                cout << i - 500000 << ' ';

                m[i]--;
                t++;
            }
            else
            {
                i--;
            }
        }
        cout << endl;
    }
    return 0;
}