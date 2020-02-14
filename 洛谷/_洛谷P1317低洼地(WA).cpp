#include <iostream>
using namespace std;

int main()
{
    int n, a[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= a[i + 1])
        {
            if (a[i + 1] < a[i + 2] && a[i + 1] < a[i])
            {
                m++;
                continue;
            }

            i++;
        }
    }
    cout << m;
    return 0;
}