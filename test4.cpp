#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX_N 1000
#define INFINITE 1000000
int t, n, x, y, max;
struct Platform
{
    int Lx, Rx, h;
};
Platform aPlatform[MAX_N + 10];
int aLeftMinTime[MAX_N + 10], aRightMinTime[MAX_N + 10];
int MyCompare(const void *e1, const void *e2)
{
    Platform *p1, *p2;
    p1 = (Platform *)e1;
    p2 = (Platform *)e2;
    return p2->h - p1->h; //从大到小排列
}
int MinTime(int L, bool bLeft)
{
    int y = aPlatform[L].h;
    int i, x;
    if (bLeft)
        x = aPlatform[L].Lx;
    else
        x = aPlatform[L].Rx;
    for (i = L + 1; i <= n; i++) //找到下一张板子
    {
        if (aPlatform[i].Lx <= x && aPlatform[i].Rx >= x)
            break;
    }
    if (i <= n) //找到了
    {
        if (y - aPlatform[i].h > max) //太高
            return INFINITE;
    }
    else //没找到
    {
        if (y > max) //离地面太高
            return INFINITE;
        else
            return y;
    } //特殊情况处理完毕
    int nLeftTime = y - aPlatform[i].h + x - aPlatform[i].Lx;
    int nRightTime = y - aPlatform[i].h + aPlatform[i].Rx - x;
    if (aLeftMinTime[i] ==
        -1) //还没有存储值
        aLeftMinTime[i] = MinTime(i, true);
    if (aRightMinTime[i] ==
        -1)
        aRightMinTime[i] = MinTime(i, false);
    nLeftTime += aLeftMinTime[i];
    nRightTime += aRightMinTime[i];
    if (nLeftTime < nRightTime)
        return nLeftTime;
    return nRightTime;
}
int main(void)
{
    int i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        memset(aLeftMinTime, -1, sizeof(aLeftMinTime));
        memset(aRightMinTime, -1, sizeof(aRightMinTime));
        scanf("%d%d%d%d", &n, &x, &y, &max);
        aPlatform[0].Lx = x;
        aPlatform[0].Rx = x;
        aPlatform[0].h = y; //长度为0的板子
        for (j = 1; j <= n; j++)
            scanf("%d%d%d", &aPlatform[j].Lx,
                  &aPlatform[j].Rx, &aPlatform[j].h);
        qsort(aPlatform, n + 1, sizeof(Platform), MyCompare);
        printf("%d\n", MinTime(0, true));
    }
    return 0;
}
