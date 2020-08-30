#include <iostream>

int main()
{
    using namespace std;
    int a[100], n, b[100] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                b[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}