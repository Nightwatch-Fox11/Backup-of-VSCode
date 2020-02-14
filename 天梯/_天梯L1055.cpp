#include <iostream>

using namespace std;

int main()

{
    int t1, t2;
    cin >> t1 >> t2;
    int te[2] = {0};
    for (int i = 0; i < 3; i++)
    {
        int t;
        cin >> t;
        te[t]++;
    }
    if ((t1 > t2 && te[0]) || (t1 < t2 && te[0] == 3))
    {
        cout << "The winner is a: " << t1 << " + " << te[0];
    }
    else
    {
        cout << "The winner is b: " << t2 << " + " << te[1];
    }

    return 0;
}