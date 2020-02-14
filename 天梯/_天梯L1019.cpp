#include <iostream>
using namespace std;
int main()
{
    int a1, a2, a3 = 0, a4 = 0;
    cin >> a1 >> a2;
    int n;
    cin >> n;
    char flag;
    struct a
    {
        int b[4] = {0};
    } k[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> k[i].b[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (k[i].b[0] + k[i].b[2] == k[i].b[1] && k[i].b[0] + k[i].b[2] != k[i].b[3])
        {
            a1--;
            a3++;
        }
        else if (k[i].b[0] + k[i].b[2] != k[i].b[1] && k[i].b[0] + k[i].b[2] == k[i].b[3])
        {
            a2--;
            a4++;
        }
        if (a1 == -1 && a2 != -1)
        {
            cout << 'A' << endl
                 << a4;
            a1 = a2 = 200;
        }
        if (a2 == -1 && a1 != -1)
        {
            cout << 'B' << endl
                 << a3;
            a1 = a2 = 200;
        }
    }

    return 0;
}