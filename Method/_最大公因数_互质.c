#include <stdio.h>
int gcd(int a, int b) //法一
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int gcd(int a, int b) //法二
{
    return a % b == 0 ? b : gcd(b, a % b);
}
//递归法求最大公约数，当最大公约数是1的时候，两个数互质
// if(gcd(x,y)==1)那么x,y互质