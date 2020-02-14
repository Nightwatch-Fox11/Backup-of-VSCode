#include <iostream>

int main()
{
    using namespace std;
    int n, a[100], k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                continue;
            }

            for (int l = j + 1; l < n; l++)
            {

                if (a[i] == a[j] + a[l])
                {
                    k++;
                    goto don;
                }
            }
        }
    don:;
    }
    cout << k;

    return 0;
}