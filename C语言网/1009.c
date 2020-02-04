//给出一个不多于5位的整数，要求 1、求出它是几位数 2、分别输出每一位数字 3、按逆序输出各位数字，例如原数为321,应输出123
#include <stdio.h>

int main()
{
    int a, b[5], i = 0;
    scanf("%d", &a);
    while (1)
    {
        b[i++] = a - ((a / 10) * 10);
        a /= 10;
        if (a == 0)
            break;
    }
    printf("%d\n", i);

    for (int d = i - 1; d >= 0; d--)
        printf("%-2d", b[d]);
    printf("\n");
    for (int c = 0; c < i; c++)
        printf("%d", b[c]);
    return 0;
}