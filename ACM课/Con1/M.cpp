#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        string a;
        cin >> a;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if ((i + 1) % 2)
            {
                sum1 += a[i] - '0';
            }
            else
            {
                sum2 += a[i] - '0';
            }
        }
        if ((sum1 + sum2) % 3)
        {
            cout << "No ";
        }
        else
        {
            cout << "Yes ";
        }

        if (abs(sum1 - sum2) % 11)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
        cout << endl;
    }
    return 0;
}