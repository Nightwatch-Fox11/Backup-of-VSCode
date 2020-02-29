#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;
/*inline int squar(int x) { return x * x; }
int main()
{
    using namespace std;

    int *p = new int;
    *p = 45;
    cout << *p;
    delete p;

    cout << squar(4);
}
int main()
{
    char a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << a << b << c << d;
}*/
int main()
{
    float array[9] = {6.21, 9.19, 6.34, 9.22, 6.85, 8.50, 6.85, 6.95, 6.03};
    float sum1 = accumulate(array, array + 9, 0);
    float sum2 = 0;
    for (int i = 0; i < 9; i++)
    {
        sum2 += array[i];
    }

    printf("%.2f,%.2f", sum1, sum2);
    return 0;
}
