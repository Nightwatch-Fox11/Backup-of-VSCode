//一个数如果恰好等于不包含它本身所有因子之和，这个数就称为"完数"。
//例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。 编程序找出N之内的所有完数，并按下面格式输出其因子
//6 its factors are 1 2 3
//28 its factors are 1 2 4 7 14
//496 its factors are 1 2 4 8 16 31 62 124 248
#include <stdio.h>

int main()
{
    int a[100], b, *p, i, sum = 0, k = 0;
    scanf("%d", &b);
    for (int m = 1; m <= b; m++)
    {
        for (i = 1; i < b; i++)
        {
            if (m % i == 0)
                a[k++] = i;
        }
        for (p = a; p < a + k; p++)
            sum += *p;
        if (sum == b)
        {
            printf("%d its factors are ", b);
            for (p = a; p < a + k; p++)
            {
                printf("%d", *p);
            }
        }
    }
    return 0;
}