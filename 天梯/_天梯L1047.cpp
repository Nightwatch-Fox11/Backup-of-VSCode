#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    struct a
    {
        string m;
        int t1;
        int t2;
    } t[n];
    for (int i = 0; i < n; i++)
    {

        cin >> t[i].m >> t[i].t1 >> t[i].t2;
        if (t[i].t1 < 15 || t[i].t1 > 20 || t[i].t2 < 50 || t[i].t2 > 70)
        {

            cout << t[i].m << endl;
        }
    }

    return 0;
}