/*
有一棵二叉树，最大深度为D，且所有叶子的深度都相同。所有结点从上到下从左到右编号为1，2，3，…，2^(D-1)。在结点1处放一个小球，它会往下落。
每个内点上都有一个开关，初始全部关闭，当每次有小球落到一个开关上时，它的状态都会改变。当小球到达一个内结点时，如果该结点上的开关关闭，
则往左走，否则往右走。如下图所示。一些小球从结点1处依次开始下落，最后一个小球将会落到哪儿呢？输入叶子深度D和小球个数I，
输出第I个小球最后所在的叶子编号。假设I不超过整棵树的叶子个数。D<=20。输入最多包含1000组数据。
*/

#include <bits/stdc++.h>
using namespace std;
// 方法一:直接模拟
/*
int a[1 << 20];
int main()
{
    int T;a
    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof(a));
        int D, I, k;
        cin >> D >> I;
        for (int i = 0; i < I; i++)
        {
            for (k = 1;;)
            {
                a[k] = !a[k];
                k = a[k] ? 2 * k : 2 * k + 1;
                if (k > ((1 << D) - 1))
                {
                    break;
                }
            }
        }
        cout << k / 2 << endl;
    }
    return 0;
}
*/
int main()
{

    return 0;
}