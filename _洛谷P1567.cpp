#include <iostream>
int a[1000000];
int main()
{
    using namespace std;
    int n, k = 1, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            k++;
            if (k > max)
            {
                max = k;
            }
        }
        else
        {
            if (k > max)
            {
                max = k;
            }
            k = 1;
        }
    }
    cout << max;

    return 0;
}