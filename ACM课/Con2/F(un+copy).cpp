/* unfinished 仿照下式完成此string版本
#include <bits/stdc++.h>
using namespace std;
int m[20];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(m, 0, sizeof(m));
    int n;
    string a;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        while (n--)
        {
            getline(cin, a);
            int j = 0;
            m[j++] = (a.find(" no good") != string::npos) ? 1 : 0;
        }
        if (n & 1)
        {
            for (int i = 0; i < n / 2 + 1; i++)
            {
                if (i)
                {
                    cout << ' ' << i;
                }
                else
                {
                    cout << i;
                }
            }
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (i)
                {
                    cout << ' ' << i;
                }
                else
                {
                    cout << i;
                }
            }
        }

        for (int i = 1, j = 0; j < n; i++, j++)
        {
            if (m[j])
            {
                cout << 'O';
            }
        }

        cout << endl;
    }
    return 0;
}
*/
//copy
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, m;
    char z[102] = {};
    cin >> n;
    while (n != 0)
    {
        cin.get();
        int q[18] = {}, w[18] = {}, l;
        for (m = 1; m <= (n + 1) / 2; m++)
        {
            cin.getline(z, 100);
            l = strlen(z);
            if ((l >= 9) && (z[l - 6] == 'o') && (z[l - 7] == 'n') && (z[l - 8] == ' '))
                q[m] = -1;
            else
                q[m] = 1;
            if (m * 2 <= n)
            {
                cin.getline(z, 100);
                l = strlen(z);
                if ((l >= 9) && (z[l - 6] == 'o') && (z[l - 7] == 'n') && (z[l - 8] == ' '))
                    w[m] = -1;
                else
                    w[m] = 1;
            }
        }
        for (m = 1; m <= (n + 1) >> 1; m++)
        {
            cout << m << ' ';
        }
        cout << "Score" << endl;
        l = 0;
        for (m = 1; m <= (n + 1) / 2; m++)
        {
            if (q[m] == 1)
            {
                cout << "O ";
                l++;
            }
            else
                cout << "X ";
        }
        cout << l << endl;
        l = 0;
        for (m = 1; m <= (n + 1) / 2; m++)
        {
            if (w[m] == 1)
            {
                cout << "O ";
                l++;
            }
            else if (w[m] == -1)
                cout << "X ";
            else
                cout << "- ";
        }
        cout << l << endl;
        cin >> n;
    }
    return 0;
}