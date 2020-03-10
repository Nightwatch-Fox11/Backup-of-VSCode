#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int n;
        cin >> n;
        int *a = new int[n];
        int *b = new int[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            b[i] = i + 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int x = abs(a[i] - a[i + 1]);
            if (x >= 1 && x <= n - 1)
            {
                b[x - 1] = 0;
            }
        }
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum += b[i];
        }
        if (sum == 0)
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not jolly" << endl;
        }
        delete[] a;
        delete[] b;
    }
    return 0;
}