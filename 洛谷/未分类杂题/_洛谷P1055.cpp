#include <iostream>

int main()
{
    using namespace std;
    int a[10];
    char ch;
    for (int i = 0; i < 10; i++)
    {
    don:
        cin >> ch;
        if (ch == '-')
        {
            goto don;
        }
        a[i] = ch - 48;
    }
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        sum += a[i] * (i + 1);
    }
    if (sum % 11 == a[9] || (sum % 11 == 10 && a[9] == 40))
    {
        cout << "Right";
    }
    else
    {
        cout << a[0] << "-";
        for (int i = 1; i < 4; i++)
        {
            cout << a[i];
        }
        cout << "-";
        for (int i = 4; i < 9; i++)
        {
            cout << a[i];
        }
        if (sum % 11 == 10)
        {
            cout << "-X";
        }

        else
        {
            cout << "-" << sum % 11;
        }
    }

    return 0;
}
