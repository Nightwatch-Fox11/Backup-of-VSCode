/*    unfinished
#include <bits/stdc++.h>
using namespace std;
string a;
int m[4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(m, 0, sizeof(m));
    int x, y, t;
    cin >> x >> y >> a;
    for (auto c : a)
    {
        switch (c)
        {
        case 'L':
            m[0]++;
            break;
        case 'R':
            m[1]++;
            break;
        case 'U':
            m[2]++;
            break;
        case 'D':
            m[3]++;
            break;
        }
    }
    if

        return 0;
}
*/
// copy
#include <bits/stdc++.h>
using namespace std;
char s[100000];
int x, y, t;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%d%d%d", &x, &y, &t);
        scanf("%s", s + 1);
        int ans = 0, nx = 0, ny = 0, flot = 0;
        for (int i = 1; s[i]; i++, ans++)
        {
            if (x == nx && y == ny)
            {
                flot = 1;
                break;
            }
            if (s[i] == 'L')
            {
                if (x <= 0 && nx > x)
                    nx--;
            }
            if (s[i] == 'R')
            {
                if (x >= 0 && nx < x)
                    nx++;
            }
            if (s[i] == 'U')
            {
                if (y >= 0 && ny < y)
                    ny++;
            }
            if (s[i] == 'D')
            {
                if (y <= 0 && ny > y)
                    ny--;
            }
        }
        if (flot)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return 0;
}