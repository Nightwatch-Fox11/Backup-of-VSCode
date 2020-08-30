#include <stdio.h>
#include <string.h>
int main()
{
    int L, a[10000] = {0}, M, p, q;
    scanf("%d%d", &L, &M);

        memset(a, 0, sizeof(a));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &p, &q);
        for (int j = p; j <= q; j++)
        {
            a[j] = 1;
        }
    }
    int k = 0;
    for (int i = 0; i <= L; i++)
    {
        if (a[i] == 0)
        {
            k++;
        }
    }
    printf("%d\n", k);

    return 0;
}