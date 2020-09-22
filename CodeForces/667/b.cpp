//想到均值不等式当a,b的和一定时, a,b相等时积最大，也就是最接近时，那么本题让积最小，就可以让两数差距变大
//看了一下这题好像有两种做法，一种是暴力比较，反正只有两个要操作的数a,b，
//那就先把a减到最小，再减b耗尽n，然后再进行先把b减到最小，再减a耗尽n，两次结果取最小
//第二种和我的原想法比较像，那就是看谁能减到更小，也就是所以a能到的最小值是max(x,a−n)，b能到的最小值是max(y,b−n)
//那就比较一下,那个小就优先对谁操作,剩下就对另一个数操作
//原想法是直接比较a,b最小值，显然对于最后一个样例错了。
#include <bits/stdc++.h>
using namespace std;
int T;
long long a, b, x, y, n;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d %d %d", &a, &b, &x, &y, &n);
        if (max(x, a - n) < max(y, b - n)) //令b小
        {
            swap(a, b);
            swap(x, y);
        }

        if (b - n >= y) //b将n耗尽
        {
            b -= n;
        }
        else
        {
            if (a - (n - (b - y)) >= x) //a将剩下的n耗尽
            {
                a -= (n - (b - y));
            }
            else
            {
                a = x;
            }

            b = y;
        }
        printf("%lld\n", a * b);
    }
    return 0;
}