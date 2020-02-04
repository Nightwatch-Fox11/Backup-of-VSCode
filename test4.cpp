#include <iostream>
using namespace std;

void temp(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int b = 8, c = 100;
    int &a = b;
    a = 9;
    temp(b, c);
    cout << b << ' ' << c;
}