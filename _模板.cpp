// 1
#include <iostream>
using namespace std;

int main()
{

    return 0;
}
/*2
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
    for (int i = 0; i < n; i++)
    {
        
    }
    }
    return 0;
}
3
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}
*/
inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    return x * f;
}
void in(int &read)
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    read = x; //读入优化
}