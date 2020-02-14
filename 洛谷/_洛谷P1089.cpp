#include <iostream>

int main()
{
    using namespace std;
    int a[12], t = 0, m = 0;
    for (int i = 0; i < 12; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 12; i++)
    {
        m = m + 300 - a[i];
        if (m < 0)
        {
            cout << -(i + 1);
            return 0;
        }

        if (m >= 100)
        {
            t += (m / 100) * 100;
            m %= 100;
        }
    }
    cout << m + 1.2 * t;

    return 0;
}