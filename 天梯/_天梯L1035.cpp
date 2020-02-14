#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b, c;
    int i = 1;
    while (1)
    {
        getline(cin, a);
        if (a[0] == '.')
        {
            break;
        }
        if (i == 2)
        {
            b = a;
        }
        if (i == 14)
        {
            c = a;
        }
        i++;
    }
    if (i <= 2)
    {
        cout << "Momo... No one is for you ...";
    }
    else if (i <= 14)
    {
        cout << b << " is the only one for you...";
    }
    else
    {
        cout << b << " and " << c << " are inviting you to dinner...";
    }

    return 0;
}