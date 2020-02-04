#include <stdio.h>

int is_pa(int a[])
{
    if (a[0] == a[3] && a[1] == a[2])

        return 1;

    else

        return 0;
}

void addtime(int *a, int *b)
{

    if ((*b) + 1 >= 60)
    {
        (*a)++;
        if ((*a) >= 24)
        {
            (*a) = 0;
        }

        (*b) = 0;
    }
    else
    {
        (*b)++;
    }
}
void shuzu(int c[], int a, int b)
{
    *c = a / 10;
    *(c + 1) = a % 10;
    *(c + 2) = b / 10;
    *(c + 3) = b % 10;
}

int main()
{
    int b[4], m, n, i = 0;
    scanf("%d:%d", &m, &n);
    shuzu(b, m, n);
    if (is_pa(b))
    {
        printf("0");
    }
    else
    {
        while (is_pa(b) == 0)
        {
            addtime(&m, &n);
            shuzu(b, m, n);
            i++;
        }

        printf("%d", i);
    }
    return 0;
}
