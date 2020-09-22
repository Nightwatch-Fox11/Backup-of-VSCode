//Yet Another Two Integers Problem
//很简单的一道题，没有任何算法，签到
#include <bits/stdc++.h>
using namespace std;
int T, a, b;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &a, &b);
        if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            printf("%d\n", abs(a - b) % 10 ? abs(a - b) / 10 + 1 : abs(a - b) / 10);
        }
    }

    return 0;
}