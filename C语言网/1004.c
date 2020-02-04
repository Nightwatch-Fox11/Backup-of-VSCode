#include <stdio.h>

int n;
int sum1(int a)
{
    if (a <= 1)
        return 1;
    else if (a <= 4)
        return sum1(a - 1) + 1;
    else
        return sum1(a - 1) + (a - 3);
}

int main()
{
    while (1)
    {
        scanf("%d", &n);
        if (n != 0)
            printf("%d\n", sum1(n));
        else
            return 0;
    }
    return 0;
}