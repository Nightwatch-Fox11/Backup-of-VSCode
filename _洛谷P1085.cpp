#include <iostream>

int main()
{
    using namespace std;
    int a[14];
    for (int i = 0; i < 14; i++)
    {
        cin >> *(a + i);
    }
    int b[7], i = 0, t;
    for (int m = 0; i < 7; m += 2)
    {
        *(b + i) = *(a + m) + *(a + m + 1);
        i++;
    }
    i--;
    int max = *(b + i);
    while (i >= 0)
    {
        if (*(b + i) >= max)
        {
            t = i;
            max = *(b + i);
        }
        i--;
    }
    cout << t + 1;

    return 0;
}