#include <iostream>

int main()
{
    using namespace std;
    int k, n;
    double sum, i;
    cin >> k;
    for (i = 1;; i++)
    {
        sum = sum + (1 / i);
        if (sum > k)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}