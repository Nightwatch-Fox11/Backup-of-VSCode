#include <iostream>
using namespace std;

int main()
{
    char ch;
    int n;
    cin >> ch >> n;
    char a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    char b[n][n];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            b[n - 1 - i][n - 1 - j] = a[i][j];
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != b[i][j])
            {
                flag = 1;
            }
        }
    }
    if (!flag)
    {
        cout << "bu yong dao le" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << b[i][j];
            }
        }
    }

    return 0;
}