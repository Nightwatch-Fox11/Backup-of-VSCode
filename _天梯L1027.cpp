//int[] arr = new int[]{8,3,2,1,0};
//int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};

#include <iostream>
using namespace std;

int main()
{
    int a[10] = {0};
    for (int i = 0; i < 11; i++)
    {
        char n;
        n = getchar();
        a[n - 48]++;
    }
    cout << "int[] arr = new int[]{";
    for (int i = 9; i >= 0; i--)
    {
        if (a[i])
        {
            if (i)
            {
                cout << i << ',';
            }

            else
            {
                cout << i;
            }
        }
    }

    return 0;
}