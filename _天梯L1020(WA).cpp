#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, x;
    struct a
    {
        string b;
    } k[10000];

    cin >> n;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (; j < x; j++)
        {
            getline(cin, k[i + j].b);
        }
    }

    return 0;
}