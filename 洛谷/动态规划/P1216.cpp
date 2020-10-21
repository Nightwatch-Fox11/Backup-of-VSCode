//本题为dp入门题，其中包含记忆化搜索思想，还可以使用递推方法
#include <bits/stdc++.h>
using namespace std;
int r, a[1100][1100], dd[1100][1100];

int d(int i, int j, int k)
{
    if (dd[i][j] == -1)
    {
        if (i == k) //递归终点
        {
            dd[i][j] = a[i][j];
            return dd[i][j];
        }
        if (dd[i + 1][j] == -1)
        {
            dd[i + 1][j] = d(i + 1, j, k);
        }
        if (dd[i + 1][j + 1] == -1)
        {
            dd[i + 1][j + 1] = d(i + 1, j + 1, k);
        }

        dd[i][j] = a[i][j] + (dd[i + 1][j] > dd[i + 1][j + 1] ? dd[i + 1][j] : dd[i + 1][j + 1]);
    }
    return dd[i][j];
}

int main()
{
    memset(dd, -1, sizeof(dd));
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << d(0, 0, r - 1);
    return 0;
}