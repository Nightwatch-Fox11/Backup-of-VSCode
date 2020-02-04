#include <stdio.h>

int find_least(int p, int q, int l[p][q])
{
    int least = 100, sum = 0;
    for (int j = 0; j < q; j++)
    {
        for (int i = 0; i < p; i++)
        {
            if (l[i][j] != -1 && l[i][j] <= least)
            {
                least = l[i][j];
            }
        }
        sum += least;
        least = 100;
    }
    return sum;
}

int main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    int k[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &k[i][j]);
        }
    }
    printf("%d", find_least(m, n, k));
    return 0;
}