#include <iostream>

int main()
{
    using namespace std;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d >= b)
    {
        cout << c - a << ' ' << d - b;
    }
    else
    {
        cout << c - a - 1 << ' ' << 60 - b + d;
    }
    return 0;
}