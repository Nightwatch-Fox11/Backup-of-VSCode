#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        float a[k];
        for (int j = 0; j < k; j++)
        {
            cin >> a[j];
        }
        float sum2 = 0;
        for (int j = 0; j < k; j++)
        {
            sum2 += a[j];
        }
        printf("%.2f\n", (sum2 - *min_element(a, a + k) - *max_element(a, a + k)) / (k - 2));
    }

    return 0;
}