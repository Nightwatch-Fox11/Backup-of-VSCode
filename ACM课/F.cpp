#include <cstring>
#include <iostream>

using namespace std;

int a[1010];

int main()
{
    int mm;
    cin >> mm;
    for (int l = 0; l < mm; l++)
    {
        int n, k, first = 1;
        memset(a, 0, sizeof(a));
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % i == 0)
                {
                    a[j] = !a[j];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i])
            {
                if (first)
                    first = 0;
                else
                    cout << ' ';
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}