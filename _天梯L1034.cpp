#include <iostream>

using namespace std;

int main()
{
    int m[1001] = {0}, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int temp;
            cin >> temp;
            m[temp]++;
        }
    }
    int t1 = 0, t2 = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (m[i] > t2)
        {
            t1 = i;
            t2 = m[i];
        }
        else if (m[i] == t2)
        {
            if (i > t1)
            {
                t1 = i;
            }
        }
    }
    cout << t1 << ' ' << t2;

    return 0;
}