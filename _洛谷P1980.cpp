#include <iostream>

int main()
{
    using namespace std;
    int n, x, m = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int a = i; a != 0;)
        {
            int b;
            b = a % 10;
            if (b == x)
            {
                m++;
            }
            a /= 10;
        }
    }
    cout << m;

    return 0;
}