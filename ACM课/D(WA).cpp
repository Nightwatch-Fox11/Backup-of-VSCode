#include <iostream>
#include <cstdio>
#include <algorithm>
int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
using namespace std;
void fenshu(int m1, int m2)
{
    if (m1 * m2 < 0)
    {
        if (!abs(m1) % abs(m2))
        {
            cout << '-' << abs(m1) % abs(m2);
        }
        else
        {
            cout << '-' << abs(m1) % gcd(abs(m1), abs(m2)) << '/' << abs(m2) % gcd(abs(m1), abs(m2));
        }
    }
    else
    {
        if (!abs(m1) % abs(m2))
        {
            cout << abs(m1) % abs(m2);
        }
        else
        {
            cout << abs(m1) % gcd(abs(m1), abs(m2)) << '/' << abs(m2) % gcd(abs(m1), abs(m2));
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        char e;
        scanf("%d %d %d %d %c", &a, &b, &c, &d, &e);
        int m1, m2;
        switch (e)
        {
        case '*':
            m1 = a * c;
            m2 = b * d;
            fenshu(m1, m2);
            break;
        case '-':
            m1 = a * d - b * c;
            m2 = b * d;
            fenshu(m1, m2);
            break;
        case '+':
            m1 = a * d + b * c;
            m2 = b * d;
            fenshu(m1, m2);
            break;

        case '/':
            m1 = a * d;
            m2 = b * c;
            fenshu(m1, m2);
            break;
        }
    }

    return 0;
}