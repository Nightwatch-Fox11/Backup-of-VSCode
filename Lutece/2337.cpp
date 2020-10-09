//本题具有一定迷惑性，此题的x大概率是求不出来的，只是假定一定存在一个充分大的(极大的)数，使得它模每一个数都能取到最大值，也就是该数-1
#include <bits/stdc++.h>
using namespace std;
int n, temp, ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ans += temp - 1;
    }
    cout << ans;
    return 0;
}