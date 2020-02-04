#include <iostream>

int main()
{
    using namespace std;
    int a;
    char b;
    cin >> a >> b;
    if (a % 2 == 0)
    {
        for (int i = 0; i < a; i++)
        {
            cout << b;
        }
        cout << '\n';
        for (int i = 0; i < a / 2 - 2; i++)
        {
            cout << b;
            for (int j = 0; j < a - 2; j++)
            {
                cout << " ";
            }
            cout << b << '\n';
        }

        for (int i = 0; i < a; i++)
        {
            cout << b;
        }
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            cout << b;
        }
        cout << '\n';
        for (int i = 0; i < a / 2 - 1; i++)
        {
            cout << b;
            for (int j = 0; j < a - 2; j++)
            {
                cout << " ";
            }
            cout << b << '\n';
        }
        for (int i = 0; i < a; i++)
        {
            cout << b;
        }
    }

    return 0;
}