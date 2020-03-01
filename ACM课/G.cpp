//蛇形填数
#include <iostream>
#include <cstring>

using namespace std;
int a[100][100];
int main()
{
    int ll;
    cin >> ll;
    for (int h = 0; h < ll; h++)
    {

        int n, count, x, y;
        cin >> n;
        memset(a, 0, sizeof(a));
        count = a[x = 0][y = n - 1] = 1;
        while (count < n * n)
        {
            while (x + 1 < n && !a[x + 1][y])
                a[++x][y] = ++count;
            while (y - 1 >= 0 && !a[x][y - 1])
                a[x][--y] = ++count;
            while (x - 1 >= 0 && !a[x - 1][y])
                a[--x][y] = ++count;
            while (y + 1 < n && !a[x][y + 1])
                a[x][++y] = ++count;
        }
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < n; y++)
            {
                printf("%4d", a[x][y]);
            }
            cout << endl;
        }
    }
    return 0;
}