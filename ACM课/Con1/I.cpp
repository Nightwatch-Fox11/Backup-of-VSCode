#include <iostream>
using namespace std;
char a[100][100];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
            char ch = getchar();
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}