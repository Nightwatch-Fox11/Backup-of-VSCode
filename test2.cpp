#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cns = 0;
    string a("1010000");
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (i != a.size() - 2)
        {
            if (a[i] - a[i + 1])
            {
                continue;
            }
            else
            {

                if (a[i + 2] == a[i + 1])
                {
                    if (a[i] == '1')
                    {
                        a[i + 1] = '0';
                    }
                    else
                    {
                        a[i + 1] = '1';
                    }
                }
                else
                {
                    int temp = a[i + 2];
                    a[i + 2] = a[i + 1];
                    a[i + 1] = temp;
                }
                cns++;
            }
        }
        else
        {
            if (a[i] - a[i + 1])
            {
                continue;
            }
            else
            {
                cns++;
            }
        }
    }
    cout << cns;
    return 0;
}