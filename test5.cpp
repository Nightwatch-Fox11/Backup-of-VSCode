#include <iostream>
inline int squar(int x) { return x * x; }
int main()
{
    using namespace std;

    int *p;
    p = new int;
    *p = 45;
    cout << *p;
    delete p;

    cout << squar(4);
}