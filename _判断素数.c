#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, flag;
    long long x;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld", &x);
        flag = 1;
        for (i = 2; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (x == 1 || flag == 0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
//素数：除1以外只能被其自身整除，注意1不是素数，2是素数
