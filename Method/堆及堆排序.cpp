// 小顶堆：子节点值>父节点值     大顶堆：子节点值<父节点值
#include <iostream>
using namespace std;
// 用大顶堆实现数组从小到大排序
int main()
{
    int i, k, n, t, a[200]; //a[0]不使用
    cin >> n;
    for (i = 1; i <= n; i++) //初始化数组
    {
        cin >> a[i];
    }
    for (i = 2; i <= n; i++) //初始化堆
    {
        k = i;
        while (k)
        {
            if (k / 2 <= 0 || a[k] <= a[k / 2])
            {
                break;
            }
            swap(a[k], a[k / 2]);
            k /= 2;
        }
    }
    //开始进行删顶来排序
    for (i = n; i > 0; i--)
    {
        swap(a[i], a[1]);
        k = 1;
        while (k < i)
        {
            t = k;                            //t存储左右儿子及父节点中最大值下标
            if (2 * k < i && a[k * 2] > a[t]) //左儿子存在且值大于父节点
            {
                t = 2 * k;
            }
            if (2 * k + 1 < i && a[k * 2 + 1] > a[t]) //右儿子存在且值大于父节点
            {
                t = 2 * k + 1;
            }
            if (t == k) //父节点此时最大
            {
                break;
            }
            swap(a[k], a[t]);
            k = t;
        }
    }
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}
//小顶堆实现
int main()
{
    int k, n, t, i, a[1001];
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 2; i <= n; i++)
    {
        k = i;
        while (k)
        {
            if (a[k] <= a[k / 2] || k / 2 <= 0)
            {
                break;
            }
            swap(a[k], a[k / 2]);
            k /= 2;
        }
    }
    for (i = n; i > 0; i--)
    {
        swap(a[i], a[1]);
        k = 1;
        while (k < i)
        {
            t = k;                            //t存储左右儿子及父节点中最大值下标
            if (2 * k < i && a[k * 2] < a[t]) //左儿子存在且值大于父节点
            {
                t = 2 * k;
            }
            if (2 * k + 1 < i && a[k * 2 + 1] < a[t]) //右儿子存在且值大于父节点
            {
                t = 2 * k + 1;
            }
            if (t == k) //父节点此时最大
            {
                break;
            }
            swap(a[k], a[t]);
            k = t;
        }
    }

    return 0;
}