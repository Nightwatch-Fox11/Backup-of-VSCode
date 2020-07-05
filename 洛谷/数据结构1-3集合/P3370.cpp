#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> a;
string b;
int n, ans;
inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    return x * f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = read();
    while (n--)
    {
        getline(cin, b);
        if (!a[b])
        {
            ans++;
            a[b] = !a[b];
        }
    }
    printf("%d", ans);

    return 0;
}