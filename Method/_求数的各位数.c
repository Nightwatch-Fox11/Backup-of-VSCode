#include <stdio.h>
#include <math.h>

void chuli(int n, int a[])
{
    int k, i;
    for (i = 0; n != 0; i++)
    {
        n /= 10;
    }
    k = i;
    for (i = 0; i < n; i++)
    {
        *(a + i) = n % 10;
        n /= 10;
    }
}