#include <stdio.h>
#include <stdlib.h>
typedef struct _monkey
{
    int id;
    struct _monkey *next;
} monkey;
monkey *create(int m)
{
    int i;
    monkey *p = (monkey *)malloc(sizeof(monkey)), *last = p;
    last
        ->id = 1;
    for (i = 2; i <= m; i++)
    {
        last
            ->next = (monkey *)malloc(sizeof(monkey));
        last = last
                   ->next;
        last
            ->id = i;
    }
    last
        ->next = p;
    return p;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int i, n, m, cnt;
        monkey *p, *pre;
        scanf("%d%d", &m, &n);
        pre = p = create(m);
        for (i = 1; i < m; i++)
        {
            cnt = 1;
            while (cnt < n)
            {
                pre = p;
                p = p
                        ->next;
                cnt++;
            }
            pre
                ->next = p
                             ->next;
            free(p);
            p = pre
                    ->next;
        }
        printf("%d\n ", p
                            ->id);
        free(p);
    }
    return 0;
}