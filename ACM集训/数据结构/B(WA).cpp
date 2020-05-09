//此题思路是先用并查集初始化数据，然后求其中的连通块个数,此时要注意路径压缩以整体的减小时间复杂度（平时做并查集查找的时候就要注意压缩），
//也就是wxp课上讲的查找过程中find函数的递归构造构造，在查找的同时进行了路径压缩使得接下来的查找复杂度降低
#include <bits/stdc++.h>
using namespace std;
int a[1000001]; //a[0]弃之不用
bool isRoot[1000001];
int dep[1000001];
int find(int u) //find函数很关键（涉及路径压缩）！！！
{
    int r = u;
    while (a[r] != r)
    {
        dep[r]++;
        if (r == 2)
        {
            a[r] = r;
        }
        r = a[r]; //找到他的前导结点
    }
    int i = u, j;
    while (i != r) //路径压缩算法
    {
        j = a[i]; //记录x的前导结点
        a[i] = r; //将i的前导结点设置为r根节点
        i = j;
    }
    return r;
}
void Union(int x, int y) //合并操作
{
    int fax = find(x);
    int fay = find(y);
    if (fax != fay)
        //两者的根节点不一样才进行合并操作
        a[fax] = fay;
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        isRoot[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    init(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        isRoot[find(i)] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += isRoot[i];
    }
    cout << ans << endl;

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int a[1000001]; //a[0]弃之不用
bool isRoot[1000001];
int dep[1000001];
int find(int u) //find函数很关键（涉及路径压缩）！！！
{
    int r = u;
    while (a[r] != r)
    {
        dep[r]++;
        if (r == 2)
        {
            a[r] = r;
        }
        r = a[r]; //找到他的前导结点
    }
    int i = u, j;
    while (i != r) //路径压缩算法
    {
        j = a[i]; //记录u的前导结点
        a[i] = r; //将i的前导结点设置为r根节点
        i = j;
    }
    return r;
}

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        isRoot[find(i)] = true;
        ans += isRoot[i];
    }
    cout << ans << endl;
    return 0;
}
*/