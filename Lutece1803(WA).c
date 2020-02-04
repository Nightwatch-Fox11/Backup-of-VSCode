#include <stdio.h>

int find_larggest(int a[], int n)
{
    int max = 0, t;
    for (int i = 0; i < n; i++)
    {
        if ((*(a + i)) >= max)
        {
            max = *(a + i);
            t = i;
        }
    }
    return t;
}
int chongfu(int a[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        if (a[i] == a[k])
        {
            return 0;
        }
    }
    for (int i = k + 1; i < n; i++)
    {
        if (a[i] == a[k])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n, b, k, m = 0;
    scanf("%d %d", &n, &b);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (1)
    {

        if ((b - 1) == find_larggest(a, n) && chongfu(a, n, b - 1))
        {
            printf("%d", m);
            return 0;
        }
        if ((b - 1) == find_larggest(a, n) && !chongfu(a, n, b - 1))
        {
            a[b - 1] -= 1;
            k = find_larggest(a, n);
            a[k] -= 1;
            for (int i = 0; i < n; i++)
            {
                (*(a + i))++;
            }
            a[b - 1] += 1;
            m++;
            continue;
        }
        if ((b - 1) != find_larggest(a, n))
        {
            k = find_larggest(a, n);
            a[k] -= 1;
            for (int i = 0; i < n; i++)
            {
                *(a + i) += 1;
            }
            m++;
            continue;
        }
    }
}