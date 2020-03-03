#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int year, month, day, sum = 0;
        cin >> year >> month >> day;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            for (int i = month - 1; i >= 1; i--)
            {
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    sum += 31;
                }
                else if (i == 2)
                {
                    sum += 29;
                }
                else
                {
                    sum += 30;
                }
            }
            sum += day;
            cout << sum << endl;
        }
        else
        {
            for (int i = month - 1; i >= 1; i--)
            {
                if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    sum += 31;
                }
                else if (i == 2)
                {
                    sum += 28;
                }
                else
                {
                    sum += 30;
                }
            }
            sum += day;
            cout << sum << endl;
        }
    }

    return 0;
}