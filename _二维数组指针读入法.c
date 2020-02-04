#include <stdio.h>

int main()
{
    int a[3][3];

    for (int *p = &a[0][0]; p <= &a[2][2]; p++)
    {
        scanf("%d", p);
    }
    for (int *p = &a[0][0]; p <= &a[2][2]; p++)
    {
        printf("%d", *p);
    }

    return 0;
}