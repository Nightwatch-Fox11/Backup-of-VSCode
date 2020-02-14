#include <iostream>

using namespace std;

int main()
{
    int n, a1 = 0, a2 = 0, tem;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tem;
        if (tem % 2 == 0)
        {
            a2++;
        }
        else
        {
            a1++;
        }
    }
    cout << a1 << ' ' << a2;

    return 0;
}