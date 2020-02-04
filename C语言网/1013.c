//求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字，为2。 例如，n=5时=2+22+222+2222+22222，n由键盘输入。

#include <stdio.h>

int paa(int n)
{
    if (n <= 1)
        return 2;
    else
        return 10 * paa(n - 1) + 2;
}

int main()
{
    int *p, b[100], c, sum, *i, k = 1;
    scanf("%d", &c);
    for (i = b + 1; i <= b + c; i++)
    {
        *i = paa(k++);
    }

    for (p = b + 1; p <= b + c; p++)
    {
        sum += *p;
    }
    printf("%d", sum);
    return 0;
}