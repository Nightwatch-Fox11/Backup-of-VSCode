#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int n, m;
    char k;
    cin >> n >> k;
    m = sqrt((n + 1) / 2);
    for (int j = m; j > 0; j--)
    {
        for (int i = 0; i < m - j; i++)
        {
            cout << ' ';
        }

        for (int l = 0; l < 2 * j - 1; l++)
        {
            cout << k;
        }

        cout << endl;
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 0; j < m - i; j++)
        {
            cout << ' ';
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << k;
        }

        cout << endl;
    }
    cout << n - 2 * m * m + 1;

    return 0;
}