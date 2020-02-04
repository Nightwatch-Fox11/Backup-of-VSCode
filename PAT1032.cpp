#include <iostream>

int main()
{
    using namespace std;
    int a[100001] = {0}, b;
    cin >> b;
    int k, m, max = -1, maxnum;
    for (int i = 0; i < b; i++)
    {
        cin >> k >> m;
        a[k] += m;
        if (a[k] > max)
        {
            max = a[k];
            maxnum = k;
        }
    }
    cout << maxnum << " " << max;

    return 0;
}