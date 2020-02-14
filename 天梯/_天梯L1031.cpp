#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, a[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (fabs(t2 - (t1 - 100) * 1.8) < 0.1 * (t1 - 100) * 1.8)
        {
            a[i] = 1;
        }
        else if ((t2 > (t1 - 100) * 1.8))
        {
            a[i] = 2;
        }
        else
        {
            a[i] = 3;
        }
    }
    for (int i = 0; i < n; i++)
    {
        switch (a[i])
        {
        case 1:
            cout << "You are wan mei!" << endl;
            break;
        case 2:
            cout << "You are tai pang le!" << endl;
            break;

        case 3:
            cout << "You are tai shou le!" << endl;
            break;
        }
    }

    return 0;
}