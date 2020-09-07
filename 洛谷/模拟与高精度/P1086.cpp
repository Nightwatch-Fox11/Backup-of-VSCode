//P1086 花生采摘，一道模拟题，没什么算法，就是实际模拟
#include <bits/stdc++.h>
using namespace std;
int arr[21][21], M, N, K;
int main()
{
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int totaltime = 0, totalnum = 0, curi = 0, curj;
    while (totaltime < K)
    {
        int maxn = 0, maxi, maxj;
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (arr[i][j] > maxn)
                {
                    maxn = arr[i][j];
                    maxi = i;
                    maxj = j;
                }
            }
        }

        if (maxn == 0)
        {
            break;
        }
        if (curi == 0)
        {
            curj = maxj;
        }
        if (1 + maxi + abs(curi - maxi) + abs(curj - maxj) + totaltime <= K)
        {
            totaltime += abs(curi - maxi) + abs(curj - maxj) + 1; //一定注意这句话的位置要在给curi curj赋新值之前
            curi = maxi;
            curj = maxj;
            totalnum += arr[maxi][maxj];
            arr[maxi][maxj] = 0;
        }
        else
        {
            break;
        }
    }
    printf("%d\n", totalnum);
    return 0;
}