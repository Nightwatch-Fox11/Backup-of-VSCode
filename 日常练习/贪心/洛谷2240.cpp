//基础贪心
//开始想的三数组果然行不通，无法获得最大元素的下标，因为设计数组排序，无法单独记录下表
//因此直接结构体
#include <bits/stdc++.h>
using namespace std;
struct item
{
    int w, v;
} k[1000];
bool cmp(item a, item b)
{
    return a.v * b.w > a.w * b.v; //这里也很巧妙 此法直接节约了结构体的性价比元素，省去使用高精度
}
double ans;
int main()
{
    int N, T;
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> k[i].w >> k[i].v;
    }
    sort(k, k + N, cmp);
    for (int i = 0; i < N; i++)
    {
        if (T >= k[i].w)
        {
            ans += k[i].v;
            T -= k[i].w;
        }
        else
        {
            ans += k[i].v * T * 1.0 / (k[i].w * 1.0); //拿上能拿的部分，注意强转double
            break;
        }
    }
    printf("%.2lf", ans); //保留2位小数

    return 0;
}