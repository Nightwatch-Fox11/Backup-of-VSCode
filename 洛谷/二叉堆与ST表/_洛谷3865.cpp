//ST表模板题
//ST算法是解决RMQ（区间最值）问题，它能在O（nlogn）的时间预处理，然后O（1）查询回答。其原理是倍增，
#include <bits/stdc++.h>
using namespace std;
int logn[2000001], f[2000001][21]; //此处数组的大小：logn和f的第一维均取决于数据个数即正常要存入数组的元素个数，f第二维是log2(n)向下取整加一个元素。本体此处稍微开大了点
//f[i][j]表示从i位起的2^j个数中的最大数，即[i,i+2^j-1]中的最大值，从其定义中可以看出来。
void pre() //预处理出log表，节约调用log2函数的时间
{
    logn[1] = 0;
    for (int i = 2; i < 2000001; i++)
    {
        logn[i] = logn[i / 2] + 1;
    }
}
inline int read() //快速读入
{
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = read(), M = read();
    for (int i = 1; i <= N; i++)
    {
        f[i][0] = read(); //f[i][0]表示[i,i]中的最大值，只能是a[i]，故f[i][0]=a[i]
    }
    pre();
    for (int j = 1; j <= 21; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (M--)
    {
        int x = read(), y = read(), s = logn[y - x + 1];
        printf("%d\n", max(f[x][s], f[y - (1 << s) + 1][s])); //cout超时~~艹！！！
    }

    return 0;
}