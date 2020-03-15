#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int h, m;
        scanf("%d:%d", &h, &m);
        if (h >= 12)
        {
            h -= 12;
        }
        int a = abs(60 * h - 11 * m);
        if (a >= 360)
        {
            a = 720 - a;
        }
        if (a % 2)
        {
            cout << a << '/' << 2 << endl;
        }
        else
        {
            cout << a / 2 << endl;
        }
    }
    return 0;
}
//为什么   720-a ??