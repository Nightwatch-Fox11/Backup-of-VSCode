// 找规律
#include <iostream>
using namespace std;
int main()
{
    int n, va, temp, ans;
    cin >> n;
    va = 0;
    temp = 0;
    ans = 0;
    while (va < n)
    {
        temp = 2 * va + 1;
        va += temp;
        ans++;
    }
    cout << ans << endl;
    return 0;
}