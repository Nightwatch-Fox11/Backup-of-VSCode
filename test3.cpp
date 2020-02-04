#include <iostream>
using namespace std;

int main()
{
    int m = 4;
    char k = 'k';
    for (int j = m; j > 0; j--)
    {
        for (int i = 0; i < m - j; i++)
        {
            cout << ' ';
        }

        for (int l = 0; l < 2 * j - 1; l++)
        {
            cout << k;
        }
        for (int i = 0; i < m - j; i++)
        {
            cout << ' ';
        }

        cout << endl;
    }
    return 0;
}