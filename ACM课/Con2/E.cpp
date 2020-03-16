#include <bits/stdc++.h>
using namespace std;
int n, sum1, sum2;
string a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1)
    {
        sum1 = 0, sum2 = 0;
        cin >> n;
        if (n)
        {
            cin >> a;
            for (auto c : a)
            {
                if (c == 'R')
                {
                    sum1++;
                }
                else if (c == 'Y')
                {
                    sum2++;
                }
                else if (c == 'B')
                {
                    if (sum1 == 7)
                    {
                        cout << "Red" << endl;
                    }
                    else
                    {
                        cout << "Yellow" << endl;
                    }
                }
                else if (c == 'L')
                {
                    if (sum2 == 7)
                    {
                        cout << "Yellow" << endl;
                    }
                    else
                    {
                        cout << "Red" << endl;
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}