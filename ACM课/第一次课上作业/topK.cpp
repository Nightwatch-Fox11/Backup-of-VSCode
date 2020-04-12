#include <bits/stdc++.h>
using namespace std;
int b[1001];
void init(int a[]) //堆的初始化
{
    int i, k, t;
    for (i = 2; i < 1001; i++)
    {
        k = i;
        while (k)
        {
            if (k / 2 <= 0 || a[k] >= a[k / 2])
            {
                break;
            }
            swap(a[k], a[k / 2]);
            k /= 2;
        }
    }
}
void pop(int a[]) //删顶操作
{
    int i, k, t;
    for (i = 1000; i > 0; i--)
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
}
int main()
{
    int i;
    ifstream myfile("Test.txt");
    for (i = 1; i < 1001; i++)
    {
        myfile >> b[i];
    }
    init(b);
    pop(b);
    int temp;
    while (!myfile.eof()) //直到文件结尾
    {
        myfile >> temp;
        if (temp <= b[1])
        {
            continue;
        }
        else
        {
            b[1000] = temp;
            pop(b);
        }
    }
    myfile.close();
    for (i = 1; i < 1001; i++)
    {
        cout << b[i] << endl;
    }
    return 0;
}