#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char b[100][100];
int main()
{
    string a;
    int T;
    cin >> T;
    char ch = getchar();
    while (T--)
    {
        getline(cin, a);

        int r = 0, h = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != ' ')
            {
                b[r][h++] = a[i];
            }
            else
            {
                b[r++][h] = '\0';
                h = 0;
            }
        }
        for (int i = r; i >= 0; i--)
        {
            printf("%s", b[i]);
            if (i > 0)
            {
                cout << ' ';
            }
        }
        cout << endl;
        memset(b, '\0', sizeof(b));
    }
    return 0;
}