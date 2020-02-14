#include <iostream>
#include <cmath>

int main()
{
    using namespace std;
    double n, k = 2;
    cin >> n;
    for (int i = 1;; i++)
    {

        if (k >= n)
        {
            cout << i;
            break;
        }
        k = k + 2 * pow(0.98, i);
    }

    return 0;
}