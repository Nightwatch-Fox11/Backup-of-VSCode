/*
#include <bits/stdc++.h>
using namespace std;

int nxt[100];
int main()
{
    string a, b, tmp;
    a = "acabacac";
    for (int i = 1; i < a.size(); i++)
    {
        int u = nxt[i - 1];
        while (u > 0 && a[u] != a[i])
        {
            u = nxt[u - 1];
        }
        if (a[u] == a[i])
        {
            u++;
        }
        nxt[i] = u;
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << nxt[i] << ' ';
    }

    return 0;
}

const int maxl = 1e6;
string a, b, tmp;
int nxt[maxl + 100], u;
int main()
{
    cin >> a >> b;
    tmp += b;
    tmp += '#';
    tmp += a;
    for (int i = 1; i < tmp.size(); i++)
    {
        u = nxt[i - 1];
        while (u > 0 && tmp[i] != tmp[u])
        {
            u = nxt[u - 1];
        }
        if (tmp[i] == tmp[u])
        {
            u++;
        }
        nxt[i] = u;
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        if (nxt[i] >= b.size())
        {
            cout << i - b.size() - (b.size() - 1) << endl;
        }
    }
    sizeof(nxt, 0, maxl + 1);
    for (int i = 1; i < b.size(); i++)
    {
        u = nxt[i - 1];
        while (u > 0 && b[u] != b[i])
        {
            u = nxt[u];
        }
        if (b[i] == b[u])
        {
            u++;
        }
        nxt[i] = u;
    }
    cout << nxt[0];
    for (int i = 1; i < b.size(); i++)
    {
        cout << ' ' << nxt[i];
    }

    return 0;
}
*/
#include <iostream>
#include <cstring>
#define MAXN 1000010 //串最大长度
using namespace std;
int nxt[MAXN];
int la, lb, j;
char a[MAXN], b[MAXN];
int main()
{
    cin >> a + 1; //a[0] = b[0] = '',从第一位开始存储，第0位不存东西
    cin >> b + 1;
    la = strlen(a + 1); //固定写法，表示从第一位开始算长度，因为第0位相当于'\0'
    lb = strlen(b + 1);
    for (int i = 2; i <= lb; i++) //求next数组
    {
        while (j && b[i] != b[j + 1])
            j = nxt[j];
        if (b[j + 1] == b[i])
            j++;
        nxt[i] = j;
    }
    j = 0;
    for (int i = 1; i <= la; i++) //开始匹配
    {
        while (j > 0 && b[j + 1] != a[i])
            j = nxt[j];
        if (b[j + 1] == a[i])
            j++;
        if (j == lb)
        {
            cout << i - lb + 1 << endl;
            j = nxt[j];
        }
    }

    for (int i = 1; i <= lb; i++)
        cout << nxt[i] << " ";
    return 0;
}