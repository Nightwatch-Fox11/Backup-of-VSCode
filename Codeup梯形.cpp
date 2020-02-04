#include <iostream>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}