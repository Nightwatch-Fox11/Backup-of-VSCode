#include <iostream>
using namespace std;
int main()
{
    char a[100], ch;
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        a[i++] = ch;
    }
    for (int j = 0; j < i; j++)
    {
        switch (a[j])
        {
        case '-':
            if (j == i - 1)
            {
                cout << "fu";
            }
            else
            {
                cout << "fu ";
            }
            break;
        case '1':
            if (j == i - 1)
            {
                cout << "yi";
            }
            else
            {
                cout << "yi ";
            }
            break;
        case '2':
            if (j == i - 1)
            {
                cout << "er";
            }
            else
            {
                cout << "er ";
            }
            break;
        case '3':
            if (j == i - 1)
            {
                cout << "san";
            }
            else
            {
                cout << "san ";
            }
            break;
        case '4':
            if (j == i - 1)
            {
                cout << "si";
            }
            else
            {
                cout << "si ";
            }
            break;
        case '5':
            if (j == i - 1)
            {
                cout << "wu";
            }
            else
            {
                cout << "wu ";
            }
            break;
        case '6':
            if (j == i - 1)
            {
                cout << "liu";
            }
            else
            {
                cout << "liu ";
            }
            break;
        case '7':
            if (j == i - 1)
            {
                cout << "qi";
            }
            else
            {
                cout << "qi ";
            };
            break;
        case '8':
            if (j == i - 1)
            {
                cout << "ba";
            }
            else
            {
                cout << "ba ";
            }
            break;
        case '9':
            if (j == i - 1)
            {
                cout << "jiu";
            }
            else
            {
                cout << "jiu ";
            }
            break;
        case '0':
            if (j == i - 1)
            {
                cout << "ling";
            }
            else
            {
                cout << "ling ";
            }
            break;
        }
    }

    return 0;
}