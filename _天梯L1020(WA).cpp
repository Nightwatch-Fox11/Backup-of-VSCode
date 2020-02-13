#include <iostream>
using namespace std;

int main()
{
    int n, a[100000] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int te;
            cin >> te;
            a[te]++;
        }
    }
    int x, flag = 0;
    cin >> x;
    int b[10000], j = 0;
    for (int i = 0; i < x; i++)
    {
        int tem;
        cin >> tem;
        if (a[tem] == 0)
        {
            a[tem] = 1;
            flag = 1;
            b[j++] = tem;
        }
    }
    if (!flag)
    {
        cout << "No one is handsome";
    }
    else
    {
        if (j == 1)
        {
            printf("%5.5d", b[0]);
        }
        else
        {
            for (int i = 0; i < j - 1; i++)
            {
                printf("%5.5d", b[i]);
                cout << ' ';
            }
            printf("%5.5d", b[j - 1]);
        }
    }

    return 0;
}