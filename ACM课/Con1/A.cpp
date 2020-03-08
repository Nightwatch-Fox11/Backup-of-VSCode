#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a[3];
        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }
        if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2])
        {
            sort(a, a + 3);
            cout << a[1] << endl;
        }
        else
        {
            cout << max(a[0], max(a[1], a[2])) << endl;
        }
    }

    return 0;
}