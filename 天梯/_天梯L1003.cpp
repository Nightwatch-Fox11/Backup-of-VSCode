#include <iostream>
using namespace std;

int main()
{
    char ch;
    int a[10] = {0};
    while ((ch = getchar()) != '\n')
    {
        a[ch - 48]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        else
        {
            cout << i << ':' << a[i] << endl;
        }
    }

    return 0;
}