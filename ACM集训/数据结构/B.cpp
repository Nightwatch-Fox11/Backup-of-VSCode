//此题思路是先用并查集初始化数据，然后求其中的连通块个数。
//不同于常规并查集是每次读入一组共两个数据然后Union合并一次这两个数据，本题一次读入多个数据，但可以发现每读入一个数据就相当于Union两个数据i和a[i]的值x（不是a[i]本身哦！）
//最后查找连通块时，只需找到特征元素（即a[i]指向自己的元素）个数即为答案。因为Union函数已经拆开所有的环，保证了一个连通块中只有一个元素指向自身
//此时要注意路径压缩以整体的减小时间复杂度（平时做并查集查找的时候就要注意压缩），
//也就是wxp课上讲的查找过程中find函数的递归构造构造，在查找的同时进行了路径压缩使得接下来的查找复杂度降低
#include <bits/stdc++.h>
using namespace std;
int a[1000001];                                               //a[0]弃之不用
int find(int x) { return x == a[x] ? x : a[x] = find(a[x]); } //冒号后面包含了路径压缩

void Union(int u, int v)
{
    int fx = find(u), fy = find(v);
    if (fx != fy)
        a[fy] = fx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) //初始化并查集，每个元素初始均指向自己
    {
        a[i] = i;
    }
    //切记！！！！！！此处不要直接读入数组然后合并，一旦成环便会使fin函数死循环，
    //正确的做法是每次读入数据存到临时变量x中，用Union函数合并x与i，此时i指代的为以i为下标的元素，x指代的是i的钥匙所在处元素（相当于i元素的祖先），合并的是两个元素，
    //在Union函数合并过程中调用find函数时会自动给a数组赋值，所以无需给a数组赋值，赋值便死循环。
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        Union(i, x);
    }
    for (int i = 1; i <= n; i++) //判断连通块  即特征元素（即a[i]指向自己的元素）个数
        ans += (find(i) == i);
    cout << ans;
    return 0;
}
//错误总结：开始时觉得这个题不需要Union函数，直接给数组赋值即可，但是导致我无法解决成环find函数死循环问题，一顿改find函数还没改出来，所以其实思路错了，
//教训就是大部分的并查集题，这个find函数都是可行的，而且Union函数往往不可省，然后本题也收获了并查集中找环路的方法

/*  QA
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