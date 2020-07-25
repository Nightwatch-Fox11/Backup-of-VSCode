#include <iostream>
#include <cstring>
#include <cstdio>

int main()
{
    using namespace std;
    string a, c;
    getline(cin, a);
    getline(cin, c);
    int lena = a.size();
    int lenc = c.size();
    int t = 0, p;
    for (int i = 0; i < lena; i++)
    {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < lenc; i++)
    {
        c[i] = tolower(c[i]);
    }
    int j;
    for (int i = 0; i <= lenc - lena; i++)
    {
        for (j = 0; j < lena; j++)
        {
            if (c[i + j] != a[j])
            {
                break;
            }
            if (c[i - 1] != ' ' && i > 0)
            {
                break;
            }
        }
        if (j == lena && (c[i + j] == ' ' || i + j == lenc))
        {
            t++;
            if (t == 1)
            {
                p = i;
            }
        }
    }
    if (t == 0)
    {
        cout << -1;
    }
    else
    {
        cout << t << ' ' << p;
    }
    return 0;
}
