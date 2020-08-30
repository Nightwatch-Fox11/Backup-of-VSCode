#include <iostream>

int main()
{
    using namespace std;

    int a[10], b, c = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> *(a + i);
    }
    cin >> b;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] <= b + 30)
        {
            c++;
        }
    }
    cout << c;
    return 0;
}