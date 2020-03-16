/*
给你n个整数, 请按从大到小的顺序输出其中前m大的数.
Standard Input
题目包含多组测试数据, 第一行是整数T, 表示测试数据的组数. 每组测试数据有两行, 第一行有两个数n和m(0<n,m<1000000), 第二行包含n个处于区间[−500000,500000]的整数, 每个数后有一个空格.
Standard Output
对应每组测试数据按从大到小的顺序输出一行前m大的数, 每个数后应有一个空格.
Samples
Input	Output
1       213 92 3
5 3 
3 -35 92 213 -644
*/
#include <bits/stdc++.h>
using namespace std;
int m[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {

        memset(m, 0, sizeof(m));
        int a, b, c;
        cin >> a >> b;
        for (int i = 0; i < a; i++)
        {
            cin >> c;
            m[c + 500000]++;
        }
        for (int i = 1000000, t = 0; i >= 0 && t < b;)
        {
            if (m[i])
            {

                cout << i - 500000 << ' ';

                m[i]--;
                t++;
            }
            else
            {
                i--;
            }
        }
        cout << endl;
    }
    return 0;
}