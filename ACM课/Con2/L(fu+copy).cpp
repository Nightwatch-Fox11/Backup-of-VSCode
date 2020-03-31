/*
这一题仔细想一下可以发现，假设这个数组是递增的，那么f(a)必然满足
f(a) = (2n-1)a[0] + (2n-3)a[1] + …… + 1×a[n-1]
又因为我们输出的数组是字典序最小的，所以我们不妨设a[0]=1 , a[1]=2 ………… a[n-2]=n-1;*
代入后计所求得 *(2n-1)a[0] + (2n-3)a[1] + …… + 3*a[n-2] 为S
又已知a [n-1] 至少为n，如果S+n大于所给的f (a),即不符合题意；否则，a[n-1]的值就是 f(a)-S.

最后求得的数组就是1，2，3 ……n-1， f(a) - S;
*/
// copy
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n, t;
        cin >> n >> t;
        int sum = 0;
        for (int i = n; i > 1; i--)
        {
            sum += (2 * i - 1) * (n - i + 1);
        }
        int last;
        if (sum + n > t)
            cout << "-1" << endl;
        else
        {
            last = t - sum;
            for (int i = 1; i < n; i++)
                cout << i << ' ';
            cout << last << endl;
        }
    }
    return 0;
}
/*
 二。为了字典序最小，前面保持1、2、3、4、5、6……n-1，只相应的变化a[n-1]的值
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 128;
int ans[maxn], fmin = 0; //fmin记得要初始化的

void firstans(const int &n)
{
    for (int i = 1; i <= n; i++)
    {
        ans[i] = i;
    }
}
//F=(n+n-1)a1+(n-1+n-2)a2······2a(n-1)+an;  故要字典序最小，只要改变最后一项就好了，而且刚好最后一项系数为1，
//这里就这么搞算数了
void sum(const int &n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fmin = fmin + min(ans[i], ans[j]);
    }
}
int main()
{
    int n, F, T, err = -1;
    scanf("%d", &T);
    while (T--)
    {
        fmin = 0; //记得重置
        scanf("%d%d", &n, &F);
        firstans(n);
        sum(n);
        if (F < fmin)
        {
            printf("%d\n", err);
            continue;
        }
        else
        {
            ans[n] = n + F - fmin;
            for (int i = 1; i < n; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[n]); //最后一个后面不能有空格而是直接换行
        }
    }
    return 0;
}
*/