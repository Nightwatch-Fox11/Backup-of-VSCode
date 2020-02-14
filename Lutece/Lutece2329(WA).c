#include <stdio.h>

int find_max(int n, int a[n])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
        }
    }
    return max;
}

int main()
{
    int n, a[n], X, Y;
    scanf("%d", &n);
    scanf("%d %d", &X, &Y);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (X >= Y)
    {
        if (find_max(n, a) % X != 0)
        {
            printf("%d", find_max(n, a) / X + 1);
        }
        else
        {
            printf("%d", find_max(n, a) / X);
        }
    }
    else
    {
        int m;

        if (Y >= n)
        {
            if (find_max(n, a) % X != 0)
            {
                m = find_max(n, a) / X + 1;
            }
            else
            {
                m = find_max(n, a) / X;
            }
            if (m >= n)
            {
                printf("%d", n);
            }
            else
            {
                printf("%d", m);
            }
        }
        else
        {
            if (find_max(n, a) % X != 0)
            {
                printf("%d", find_max(n, a) / X + 1);
            }
            else
            {
                printf("%d", find_max(n, a) / X);
            }
        }
    }
    return 0;
}