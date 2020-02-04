#include <stdio.h>
#include <math.h>

int main()
{
    int i = 0;
    char a[20], *p, *m;
    printf("Enter a message ");
    while (1)
    {
        *(a + i++) = getchar();
        if (*(a + i - 1) == '\n')
        {
            break;
        }
    }
    p = a;
    m = a + i - 2;
    while (p != m)
    {

        if (*p < 65 || (*p > 90 && *p < 97) || *p > 122)
        {
            p++;
        }

        if (*m < 65 || (*m > 90 && *m < 97) || *m > 122)
        {
            m--;
        }

        if (*p == *m || abs(*p - *m) == 32)
        {
            p++;
            m--;
        }
        else
        {
            printf("Not ");
            return 0;
        }
    }
    if (p == m)
    {
        printf("Yes");
    }
    return 0;
}