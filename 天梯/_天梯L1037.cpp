#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (b > 0)
    {
        cout << a << '/' << b << '=';
        printf("%.2f", (float)a / b);
    }
    else if (b < 0)
    {
        cout << a << '/' << '(' << b << ')' << '=';
        printf("%.2f", (float)a / b);
    }
    else
    {
        cout << a << '/' << 0 << "=Error";
    }

    return 0;
}