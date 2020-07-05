//nt题，基本输入输出，但是暴露了我的不好习惯：喜欢把数组开在main函数里，虽然这次能过，但不是个好习惯，应该世界在main外面开一个a[2000000]
#include <bits/stdc++.h>
using namespace std;
int n, m, te;
int main()
{
    cin >> n >> m;
    int a[n] = {0};

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> te;
        cout << a[te] << endl;
    }

    return 0;
}