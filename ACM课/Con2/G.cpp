#include <bits/stdc++.h>
using namespace std;
string a;
int b[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        b[i] = a[i] - '0';
    }
    sort(b, b + a.size());
    for (int i = 0; i < a.size(); i++)
    {
        cout << b[i];
    }
    cout << endl;
    return 0;
}
