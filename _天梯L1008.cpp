#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int i = 0;
    for (; i < b - a + 1; i++)
    {
        if ((i + 1) % 5 == 0)
        {
            printf("%5d\n", a + i);
        }
        else
        {
            printf("%5d", a + i);
        }
    }
    if (i % 5 == 0)
    {
        cout
            << "Sum = "
            << (a + b) * (b - a + 1) / 2;
    }
    else
    {

        cout << endl
             << "Sum = "
             << (a + b) * (b - a + 1) / 2;
    }
    return 0;
}