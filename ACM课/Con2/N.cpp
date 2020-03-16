#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int a, b, c, j;
        cin >> a >> b >> c;
        if (a % 3 == b % 3 && a % 3)
        {
            for (int i = 0; i < c; i++)
            {
                cin >> j;
                if (j % 8 == 3 || j % 8 == 7)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
        else if (a % 3 == b % 3 && a % 3 == 0)
        {
            for (int i = 0; i < c; i++)
            {
                cin >> j;
                cout << "Yes" << endl;
            }
        }
        else if (a % 3 != 0 && b % 3 == 0)
        {
            for (int i = 0; i < c; i++)
            {
                cin >> j;
                if (j % 8 == 1 || j % 8 == 5)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
        else if (a % 3 == 0 && b % 3)
        {
            for (int i = 0; i < c; i++)
            {
                cin >> j;
                if (j % 8 == 0 || j % 8 == 4)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < c; i++)
            {
                cin >> j;
                if (j % 8 == 2 || j % 8 == 6)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
        }
    }
    return 0;
}