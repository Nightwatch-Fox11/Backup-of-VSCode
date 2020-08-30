#include <iostream>

int main()
{
    using namespace std;
    int x;
    unsigned long long n, lu = 0;
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        if (x != 6 && x != 7)
        {
            lu++;
        }

        if (x == 7)
        {
            x = 1;
            continue;
        }

        x++;
    }
    cout << lu * 250;

    return 0;
}