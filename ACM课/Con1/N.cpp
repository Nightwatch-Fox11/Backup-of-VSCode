#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    char ch = getchar();
    while (T--)
    {

        string a;
        cin >> a;
        int flag = 0;
        for (auto c : a)
        {
            if (c == ',')
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            if (a.size() % 3 == 0)
            {

                for (int i = 0; i < a.size(); i++)
                {
                    cout << a[i];
                    if (((i + 1) % 3 == 0) && i != a.size() - 1)
                    {
                        cout << ',';
                    }
                }
            }
            else if (a.size() <= 3)
            {
                cout << a;
            }

            else
            {
                int i;
                for (i = 0; i < a.size() % 3; i++)
                {
                    cout << a[i];
                }
                cout << ',';
                for (int j = 1; i < a.size(); i++, j++)
                {
                    cout << a[i];
                    if ((j % 3 == 0) && i != a.size() - 1)
                    {
                        cout << ',';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] != ',')
                {
                    cout << a[i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}