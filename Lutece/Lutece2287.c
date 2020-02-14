#include <stdio.h>
#include <math.h>

long summ(int a[], int n)
{
    long sum;
    for (int *p = a; p < a + n; p++)
    {
        sum += pow(*p, n);
    }
    return sum;
}

void chuli(int n, int a[])
{
    int k, i;
    for (i = 0; n != 0; i++)
    {
        n /= 10;
    }
    k = i; //k为n的位数
    for (i = 0; i < k; i++)
    {
        *(a + i) = n % 10;
        n /= 10;
    }
}

int main()
{
    int n, i, a[7], k = 0;

    scanf("%d", &n);
    for (i = pow(10, n); i < pow(10, n + 1); i++)
    {
        chuli(i, a);
        if (summ(a, n) == i)
        {
            printf("%d ", i);
            k++;
        }
    }
    if (!k)
    {
        printf("-1");
    }

    return 0;
}