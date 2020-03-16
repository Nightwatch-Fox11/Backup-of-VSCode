#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    if (m & 1) //此处用位与 来判奇偶
    {
        cout << "ji";
    }
    else
    {
        cout << "ou";
    }

    return 0;
}