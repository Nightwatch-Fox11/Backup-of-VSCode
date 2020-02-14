#include <iostream>

using namespace std;

int main()
{
    char ch;
    int a[4] = {0};
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case 'g':
        case 'G':
            a[0]++;
            break;
        case 'P':
        case 'p':
            a[1]++;
            break;
        case 'L':
        case 'l':
            a[2]++;
            break;

        case 'T':
        case 't':
            a[3]++;
            break;
        }
    }
    while (a[1] || a[2] || a[3] || a[0])
    {
        if (a[0])
        {
            cout << 'G';
            a[0]--;
        }
        if (a[1])
        {
            cout << 'P';
            a[1]--;
        }
        if (a[2])
        {
            cout << 'L';
            a[2]--;
        }
        if (a[3])
        {
            cout << 'T';
            a[3]--;
        }
    }

    return 0;
}