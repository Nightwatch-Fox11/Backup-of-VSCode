#include <iostream>
using namespace std;

int main()
{
    struct a
    {
        char num[16];
        int a2;
    } k[1001];
    int n, a1;
    char tem[16];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            cin >> tem[j];
        }
        cin >> a1;
        for (int j = 0; j < 16; j++)
        {
            k[a1].num[j] = tem[j];
        }
        cin >> k[a1].a2;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < 16; j++)
        {
            cout << k[t].num[j];
        }
        cout << ' ' << k[t].a2 << endl;
    }

    return 0;
}