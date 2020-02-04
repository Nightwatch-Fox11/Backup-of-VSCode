#include <stdio.h>

int sum(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int sum;
        sum += i;
        return sum;
    }
}

int main()
{
    int k, l, h[20];
    scanf("%d", &k);
    int m = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &h[i]);
    }

    return 0;
}