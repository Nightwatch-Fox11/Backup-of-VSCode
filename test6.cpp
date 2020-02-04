#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cmath>
#include <set>
#define ll long long
using namespace std;

int main()
{
    string str, s;
    getline(cin, str);
    getline(cin, s);
    int c[1000] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        c[s[i]] = 1;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (c[str[i]] == 0)
            cout << str[i];
    }
    cout << endl;
    return 0;
}