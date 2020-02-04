#include <stdio.h>

int main()
{
    int i = 0, c[50], a[50], b[50];

    while (1)
    {
        scanf("%d %d", &a[i], &b[i]);

        printf("%d\n", a[i] + b[i]);
        i++;
    }

    return 0;
}