#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    string a;
    getline(cin, a);
    char b[60][60];
    int r = 0, h = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != ' ')
        {
            b[r][h++] = a[i];
        }
        else
        {
            b[r++][h] = '\0';
            h = 0;
        }
    }
    for (int i = r; i >= 0; i--)
    {
        printf("%s", b[i]);
        if (i > 0)
        {
            cout << ' ';
        }
    }

    return 0;
}