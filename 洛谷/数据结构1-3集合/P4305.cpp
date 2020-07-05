//本题考点哈希，使用unordered_map是因为据说这个不同于map是使用哈希实现的。大概就是一个数字对应一个bool值。本题最骚的是读入方式卡的特别死
//必须使用如下的快读函数才行，单独使scanf以及cin.tie(0)都不好使。
#include <bits/stdc++.h>
using namespace std;
int T, n, t0;
unordered_map<int, bool> a;
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
    T = read();
    while (T--)
    {
        a.clear();
        n = read();
        for (int i = 0; i < n; i++)
        {
            t0 = read();
            if (!a[t0])
            {
                if (i != 0)
                {
                    printf(" ");
                }
                printf("%d", t0);
                a[t0] = !a[t0];
            }
        }
        printf("\n");
    }

    return 0;
}