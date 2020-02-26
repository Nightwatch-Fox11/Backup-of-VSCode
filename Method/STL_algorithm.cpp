#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    //max|min|abs
    cout << max(-1, 1) << endl
         << max(2.1, 1.4) << endl
         << max(1, max(2, 5)) << endl
         << abs(-5) << endl; //abs's parameter must be int. float must use camth's fabs
    //swap
    int a = 1, b = 6;
    swap(a, b);
    cout << a << ' ' << b << endl;
    // reverse
    int c[6] = {5, 3, 6, 8, 1, 9};
    reverse(c, c + 4);
    for (int i = 0; i < 6; i++)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
    string d = "Fusd fla";
    reverse(d.begin(), d.begin() + 5);
    cout << d << endl;
    //next_permutation  solution to all permutations
    int e[10] = {1, 4, 7, 8};
    do
    {
        cout << e[0] << ' ' << e[1] << ' ' << e[2] << ' ' << e[3] << endl;
    } while (next_permutation(e, e + 4));
    // memset -1||0  must under cstring
    memset(c, -1, sizeof(c));
    for (int i = 0; i < 6; i++)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
    // fill    slower than memset
    fill(c, c + 4, -3);
    for (int i = 0; i < 6; i++)
    {
        cout << c[i] << ' ';
    }
    cout << endl;
    // sort
    int k[7] = {4, 1, 6, 3, 8, 0, 23};
    sort(k, k + 7, cmp);
    for (int i = 0; i < 7; i++)
    {
        cout << k[i] << ' ';
    }
    cout << endl;

    return 0;
}
