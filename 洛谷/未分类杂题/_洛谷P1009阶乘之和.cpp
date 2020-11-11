#include <iostream>
long factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int main()
{
    using namespace std;
    unsigned long long sum = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }
    cout << sum;
    return 0;
}
