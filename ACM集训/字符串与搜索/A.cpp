//KMP板子
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
char a[MAXN], b[MAXN];
int la, lb, u, nxt[MAXN];

int main()
{
    cin >> a + 1 >> b + 1;
    la = strlen(a + 1);
    lb = strlen(b + 1);
    for (int i = 2; i <= lb; i++)
    {
        while (u && b[u + 1] != b[i])
        {
            u = nxt[u];
        }
        if (b[u + 1] == b[i])
        {
            u++;
        }
        nxt[i] = u;
    }
    u = 0;
    int cnt = 0;
    for (int i = 1; i <= la; i++)
    {
        while (u && a[i] != b[u + 1])
        {
            u = nxt[u];
        }
        if (a[i] == b[u + 1])
        {
            u++;
        }
        if (u == lb)
        {
            if (cnt)
            {
                cout << ' ';
            }
            cout << i + 1 - lb;
            cnt++;
            u = nxt[u];
        }
    }

    return 0;
}