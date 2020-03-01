#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        int gcdd = gcd(t1, t2);
        cout << gcdd << ' ' << t1 * t2 / gcdd << endl;
    }

    return 0;
}