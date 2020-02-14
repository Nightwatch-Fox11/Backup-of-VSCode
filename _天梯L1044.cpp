#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a;
    for (int i = 0;; i++)
    {
        getline(cin, a);
        if (a[0] == 'E')
        {
            break;
        }

        if (i % (n + 1) == 0 && i != 0)
        {
            cout << a << endl;
        }
        else
        {
            switch (a[0])
            {
            case 'C':
                cout << "Bu" << endl;

                break;
            case 'J':
                cout << "ChuiZi" << endl;

                break;

            case 'B':
                cout << "JianDao" << endl;

                break;
            }
        }
    }

    return 0;
}