#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        float a;
        cin >> a;
        switch (ch)
        {
        case 'M':
            printf("%.2f\n", a / 1.09);

            break;

        default:
            printf("%.2f\n", a * 1.09);
            break;
        }
    }

    return 0;
}