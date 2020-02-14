#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    for (int i = 1;; i++)
    {
        int n;
        cin >> n;
        if (n == 250)
        {
            cout << i;
            return 0;
        }
    }

    return 0;
}