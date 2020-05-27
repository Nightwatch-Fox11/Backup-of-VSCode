//看电视   本题是区间贪心的模板题，也是区间不相交问题典例：许多开区间的最大不相交个数
#include <bits/stdc++.h>
using namespace std;
struct se
{
    int x, y;
} k[1100];
bool cmp(se a, se b)
{
    if (a.x != b.x)
    {
        return a.x > b.x;
    }
    else
    {
        return a.y < b.y;
    }
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (!n)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> k[i].x >> k[i].y;
        }
        sort(k, k + n, cmp);         //干干干！！！！！！！！！！！！！这里一定注意是n~n+K！！！要不然报错
        int ans = 1, lastx = k[0].x; //ans为答案， lastx为上次定位的左边界
        for (int i = 1; i < n; i++)
        {
            if (k[i].y <= lastx)
            {
                ans++;
                lastx = k[i].x;
            }
        }
        cout << ans << endl; //别忘记换行符啊！！！
    }
    return 0;
}