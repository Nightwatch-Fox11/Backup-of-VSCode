#include <stdio.h>

int main()
{
    int a[200], n, k;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &k);
        int i = 0;
        for (; i < n; i++)
        {
            if (a[i] == k)
            {
                printf("%d", i);
                break;
            }
        }
        if (i == n)
        {
            printf("-1");
        }
    }

    return 0;
}