/*      WA WHY!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;
char m[1000][1000];
int main()
{
    int T;
    cin >> T;
    char ch = getchar();
    while (T--)
    {

        string a, b;
        getline(cin, a);
        getline(cin, b);
        int line = b.size() / a.size();
        int flag[25] = {0};
        for (int i = 0; i < a.size(); i++)
        {
            int min = 200, k;
            for (int j = 0; j < a.size(); j++)
            {
                if (a[j] < min && !flag[j])
                {
                    min = a[j];
                    k = j;
                }
            }
            flag[k] = 1;
            int m1 = 0;
            for (int l = i * line; l < (i + 1) * line; l++)
            {

                m[m1++][k] = b[l];
            }
        }
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j <= line; j++)
            {
                cout << m[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
*/
// copy
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

const int maxn = 1005;

char a[30], s[1005], temp[1005];
int ran[30];
vector<node> v;
vector<char> v1;
struct node
{
    char s[1005];
    int val;

    bool operator<(const node &rhs) const
    {
        return val < rhs.val;
    }
};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        v.clear(), v1.clear();
        scanf("%s%s", a, s);
        int len1 = strlen(a), len2 = strlen(s);
        int res = len2 / len1;
        for (int i = 0; i < len1; i++)
        {
            ran[a[i] - 'A'] = i;
            v1.push_back(a[i]);
        }
        sort(v1.begin(), v1.end());
        node e;
        for (int i = 0; i < len1; i++)
        {
            strncpy(e.s, s + i * res, res);
            e.val = ran[v1[i] - 'A'];
            v.push_back(e);
        }
        sort(v.begin(), v.end());
        int cnt = 0;
        while (cnt < res)
        {
            for (int i = 0; i < (int)v.size(); i++)
                printf("%c", toupper(v[i].s[cnt]));
            cnt++;
        }
        printf("\n");
    }
    return 0;
}