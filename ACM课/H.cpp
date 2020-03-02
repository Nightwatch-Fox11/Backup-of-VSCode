#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int T;
    cin >> T;
    char ch = getchar();
    while (T--)
    {
        getline(cin, a);
        long long sum = 0, sum1 = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] <= '9' && a[i] >= '0')
            {
                sum *= 10;
                sum += a[i] - '0';
            }
            else
            {
                sum1 += sum;
                sum = 0;
            }
            if (i == a.size() - 1)
            {
                sum1 += sum;
            }
        }

        cout << sum1 << endl;
    }

    return 0;
}