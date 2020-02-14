#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    char ch;
    scanf("%d %c\n", &n, &ch);
    string a;
    getline(cin, a);
    if (n >= a.size())
    {
        for (int i = 0; i < n - a.size(); i++)
        {
            cout << ch;
        }
        cout << a;
    }
    else
    {
        for (int i = a.size() - n; i < a.size(); i++)
        {
            cout << a[i];
        }
    }

    return 0;
}