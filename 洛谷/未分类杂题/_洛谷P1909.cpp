#include <iostream>

int main()
{
    using namespace std;
    int n, b[3], a[6];
    cin >> n;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    if (n % a[0] == 0)
    {
        *b = (n / a[0]) * a[1];
    }
    else
    {
        *b = (n / a[0] + 1) * a[1];
    }
    if (n % a[2] == 0)
    {
        *(b + 1) = (n / a[2]) * a[3];
    }
    else
    {
        *(b + 1) = (n / a[2] + 1) * a[3];
    }
    if (n % a[4] == 0)
    {
        *(b + 2) = (n / a[4]) * a[5];
    }
    else
    {
        *(b + 2) = (n / a[4] + 1) * a[5];
    }
    int min = *b;
    for (int i = 0; i < 3; i++)
    {
        if (*(b + i) <= min)
        {
            min = *(b + i);
        }
    }
    cout << min;

    return 0;
}