#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int m[500] = {0};
    for (int i = 0; i < b.size(); i++)
    {
        m[b[i]] = 1;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (m[a[i]] == 1)
        {
            continue;
        }
        else
        {
            cout << a[i];
        }
        }

    return 0;
}