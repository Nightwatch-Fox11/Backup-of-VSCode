//一笔画问题本质是欧拉回路，图论基础+dfs，
#include <bits/stdc++.h>
using namespace std;
int house[6][6]; //邻接矩阵
void makehouse()
{
    memset(house, 0, sizeof(house));
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (i != j)
            {
                house[i][j] = 1;
            }
        }
    }
    house[4][1] = house[4][2] = house[2][4] = house[1][4] = 0;
}
void dfs(int m, int n, string s) //分别出发点，到出发点距离，路径s
{
    s += char(m + '0');
    if (n == 8)
    {
        cout << s << endl;
        return;
    }
    for (int i = 1; i < 6; i++)
    {
        if (house[m][i])
        {
            house[m][i] = house[i][m] = 0;
            dfs(i, n + 1, s);
            house[m][i] = house[i][m] = 1;
        }
    }
}
int main()
{
    makehouse();
    dfs(1, 0, "");
    return 0;
}