#include <stdio.h>

int main()
{
    int n, m, k, t;
    scanf("%d%d%d%d", &n, &m, &k, &t);
    if (n > k)
    {

        if ((n * m) % k == 0)
        {
            printf("%d", ((n * m) / k) * t);
        }
        else
        {
            printf("%d", ((n * m) / k + 1) * t);
        }
    }
    else
    {
        printf("%d", m * t);
    }

    return 0;
}