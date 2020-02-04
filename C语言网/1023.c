//用选择法对10个整数从小到大排序。

#include <stdio.h>

int k, a[10];

int find_min(int k)
{
    int min = a[0];
    for (int i = k; i < 10; i++)
    {
        if (a[i] <= min)
        {
            min = a[i];
        }
    }
    return min;
}

int main()
{
    int *p;
    for (p = a; p < a + 10; p++)
    {
        scanf("%d", p);
    }
    for (int m = 0; m < 10; m++)
    {
        printf("%d\n", find_min(m));
    }

    return 0;
}