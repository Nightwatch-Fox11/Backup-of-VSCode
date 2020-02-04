#include <iostream>
#include <cstdio>

int main()
{
    using namespace std;
    double a;
    cin >> a;
    if (a <= 150)
    {
        printf("%.1f", 0.4463 * a);
    }
    else if (a <= 400)
    {
        printf("%.1f", 150 * 0.4463 + (a - 150) * 0.4663);
    }
    else
    {
        printf("%.1f", 150 * 0.4463 + 250 * 0.4663 + (a - 400) * 0.5663);
    }

    return 0;
}