#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ios::sync_with_stdio(0);
        vector<char> vi;
        string a;
        cin >> a;
        for (auto c : a)
        {
            if (c == '(' || c == ')')
            {
                vi.push_back(c);
            }
        }
        if (vi.size() % 2 != 0 || vi[0] == ')')
        {
            cout << "No";
        }
        else
        {
            int flag = 1, lef = 0, rig = 0;
            for (int i = 0; i < vi.size() / 2; i++)
            {
                if (abs(vi[i] - vi[vi.size() - i - 1]) != 1)
                {
                    flag = 0;
                }
                if (vi[i] == '(')
                {
                    lef++;
                }
                else
                {
                    rig++;
                }
            }
            if (flag == 0 || lef <= rig)
            {
                cout << "No";
            }
            else
            {
                cout << "Yes";
            }
        }
        cout << endl;
    }
    return 0;
}
//AC代码
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int i, j;
int k[1010];
int l[1010];
char str[1010][1010];
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        scanf("%s", &str[i]);
    for (int i = 0; i < t; i++)
    {
        k[i] = 0;
        l[i] = 0;
        int len = strlen(str[i]);
        for (int j = 0; j < len; j++)
        {
            if (k[i] == 0 && str[i][j] == ')')
                l[i] = 1; //第一个是否是 右括号
            if (str[i][j] == '(')
                k[i]++;
            if (str[i][j] == ')')
                k[i]--;
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (k[i] == 0 && l[i] == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}