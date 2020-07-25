#include <iostream>
#include <stdio.h>

int main()
{
    using namespace std;
    char ch;
    long sum1 = 1, sum2 = 1;
    while ((ch = getchar()) != '\n')
    {
        sum1 *= (ch - 64);
    }
    while ((ch = getchar()) != '\n')
    {
        sum2 *= (ch - 64);
    }
    if ((sum1 % 47) == (sum2 % 47))
    {
        cout << "GO";
    }
    else
    {
        cout << "STAY";
    }

    return 0;
}
