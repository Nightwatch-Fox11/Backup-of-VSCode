// /home/fox11/文档/code/first.cpp
// 解决最小连续子列问题

#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int thhis = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        thhis += a[i];
        if (thhis > max)
        {
            max = thhis;
        }
        else if (thhis < 0)
        {
            thhis = 0;
        }
    }
    cout << max;

    return 0;
}