/*        WA   !!!!
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cns = 0;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (i != a.size() - 2)
        {
            if (a[i] - a[i + 1])
            {
                continue;
            }
            else
            {

                if (a[i + 2] == a[i + 1])
                {
                    if (a[i] == '1')
                    {
                        a[i + 1] = '0';
                    }
                    else
                    {
                        a[i + 1] = '1';
                    }
                }
                else
                {
                    int temp = a[i + 2];
                    a[i + 2] = a[i + 1];
                    a[i + 1] = temp;
                }
                cns++;
            }
        }
        else
        {
            if (a[i] - a[i + 1])
            {
                continue;
            }
            else
            {
                cns++;
            }
        }
    }
    cout << cns;
    return 0;
}
*/
/*
题解：贪心、字符串处理
对于 1010101...... (0 ~ n-1) 如果奇数的地方不是1就 ans1++， 如果偶数的地方不是0就 ans0++，
ans = max(ans0, ans1)； //min(ans0, ans1)次交换， ans - min(ans0, ans1) 次改变司机的好坏
然后再对 010101......(0 ~ n-1) 的情况跑一遍
2个ans取最小值
复杂度 O(n)
*/
//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 8;

bool v[maxn];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, s1, s2;
    LL n, ans0 = 0, ans1 = 0, ans = 0;
    cin >> n;
    cin >> s;
    s1 = s;
    s2 = s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            v[i] = 0;
        }
        else
        {
            v[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        //cout << v[i] <<" ";
        if (i % 2 == 0)
        {
            if (v[i] == 0)
                ;
            else
                ans0++;
        }
        else
        {
            if (v[i] == 1)
                ;
            else
                ans1++;
        }
    }
    //cout << endl;
    //cout <<ans0 << " " << ans1 << endl;
    ans = max(ans0, ans1);

    ans0 = ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        //cout << v[i] <<" ";
        if (i % 2 == 0)
        {
            if (v[i] == 1)
                ;
            else
                ans0++;
        }
        else
        {
            if (v[i] == 0)
                ;
            else
                ans1++;
        }
    }
    //cout <<ans0 << " " << ans1 << endl;

    ans = min(ans, max(ans0, ans1));

    cout << ans << endl;

    return 0;
}