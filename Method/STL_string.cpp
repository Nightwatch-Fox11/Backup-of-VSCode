#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string a = "YEs aa";
    // printf("%s", a.c_str());
    cout << a.size() << ' ' << a.length();
    string b = " Fuck";
    cout << a + b;
    if (a > b)
    {
        cout << "QyEs";
    }

    return 0;
}