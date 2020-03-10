#include <bits/stdc++.h>

using namespace std;
char c[1010];
int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int j;
    for (int i = 0, j = 0; i < b.size(); i++)
    {
        if (b[i] != ' ')
            c[j++] = b[i];
    }
    c[j] = '\0';
    int L = j % a.size() == 0 ? j : (j / a.size() + 1) * a.size();
    int flag[25] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        int min = 200, k;
        for (int m = 0; m < a.size(); m++)
        {
            if (!flag[m] && c[m] < min)
            {
                min = c[m];
                k = m;
            }
        }
        flag[k] = 1;
        int l;
        for (l = k; l < j; l += a.size())
            (c[l] > 'Z') ? printf("%c", c[l] - 32) : printf("%c", c[l]);
        if (j < L)
            cout << "E";

        return 0;
    }
}