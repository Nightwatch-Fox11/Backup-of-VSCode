#include <iostream>
using namespace std;
int main()
{
    long long a, n, m;
    cin >> n >> m >> a;
    long long t1, t2;
    t1 = (n % a == 0 ? n / a : n / a + 1);
    t2 = (m % a == 0 ? m / a : m / a + 1);
    cout << (long long)(t1 * t2);

    return 0;
}