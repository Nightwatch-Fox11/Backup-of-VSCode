#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[101][101], ans[101][101];
int main()
{
    scanf("%d %d", &n, &m);
    getchar();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == '*')
            {
                ans[i][j] = '*';
            }
            else
            {
                ans[i][j] = '0';
                if (arr[i - 1][j - 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i + 1][j + 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i - 1][j + 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i + 1][j - 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i][j - 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i][j + 1] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i + 1][j] == '*')
                {
                    ans[i][j]++;
                }
                if (arr[i - 1][j] == '*')
                {
                    ans[i][j]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}