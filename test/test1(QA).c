#include <stdio.h>
int mul(int val)
{
    static int init = 1;
    return init *= val;
}
int main()
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        printf("%d,", mul(i));
    }
    return 0;
}
// 不会每次都定义一次么？