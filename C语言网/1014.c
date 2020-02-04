//求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字(n不超过20)。

#include <stdio.h>

long jie(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * jie(n - 1);
}
int main()
{
    int c, d = 1;
    long sum = 0;
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        sum += jie(d);
        d++;
    }
    printf("%ld", sum);
    return 0;
}