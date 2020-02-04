#include <iostream>
#include <cstdio>
#include <cstring>

int main()
{
    using namespace std;
    string a, b, c, d;
    int k[26] = {0};
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    getline(cin, d);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= 'Z' && a[i] >= 'A')
        {
            k[a[i] - 'A']++;
        }
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] <= 'Z' && b[i] >= 'A')
        {
            k[b[i] - 'A']++;
        }
    }
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] <= 'Z' && c[i] >= 'A')
        {
            k[c[i] - 'A']++;
        }
    }
    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] <= 'Z' && d[i] >= 'A')
        {
            k[d[i] - 'A']++;
        }
    }
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (k[i] >= max)
        {
            max = k[i];
        }
    }
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (k[j] >= i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
            if (j == 25)
            {
                cout << '\n';
            }
        }
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";

    return 0;
}