#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string a = "YEs aa";
    string c("YYYY"); //string 的另一种定义方法
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