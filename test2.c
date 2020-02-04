#include <stdio.h>
int main()
{
    int fun(int, int[], int *);
    int n, a[10], flag, i, k;
    printf("请输入一个整数");
    scanf("%d", &n);
    flag = fun(n, a, &k);
    if (flag)
    {
        printf("%d是完数，其因子是：", n);
        for (i = 0; i < k; i++)
            printf("%d", a[i]);
        printf("\n");
    }
    else
        printf("%d不是完数。\n", n);
    return 0;
}
int fun(int n, int a[], int *k)
{
    int m = 0, i, t;
    t = n;
    for (i = 0; i < n; i++)
        if (n % i == 0)
        {
            a[m] = i;
            m++;
            t = t - i;
        }
    k = m;
    if (t == 0)
        return 1;
    else
        return 0;
}
