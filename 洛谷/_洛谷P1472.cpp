#include <iostream>

int main()
{
    using namespace std;
    int a[100], i = 0, n;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        a[i++] = n;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << a[j] << " ";
    }

    return 0;
}