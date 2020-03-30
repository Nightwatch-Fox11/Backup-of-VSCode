/*
经典的蚂蚁爬木杆问题！其关键就是：两人相遇之后，如果均往回走，相当于两人继续往前走，只是身份交换而已。
而在这道题目中，不需要处理他们的身份信息，所以，他们是否回头可以忽略，都看作是一直朝前走，
这样，对结果产生影响的就只有他们的位置与方向（即他们离出口的距离），而性别则成为了一个无关因素，
所求最后时间即是最远距离所对应的时间，路程总和即是他们离出口的距离总和！
一般的木杆与蚂蚁问题在前面的1025中已经讲过了，此题中的依次掉下木杆的蚂蚁花费的时间可以同理求出，再用一个数组进行保存就可以了，
而这个题较难的就是对依次掉下木杆的蚂蚁名字进行输出。首先，我们明确：依次掉下木杆的蚂蚁掉落方向方向可以记录（这在前面求时间的过程中可以完成），
然后，我们明白，第一只从左边掉落的蚂蚁一定是一开始在最左边的蚂蚁，右边同理，也就是说，某一时刻从左边掉落的蚂蚁一定是当前最左边的蚂蚁。
而自始至终所有蚂蚁的相对位置都不会改变。这样想，处理就非常简单了。将蚂蚁的名字放到一个队列中，根据蚂蚁依次掉落的方向对蚂蚁的名字输出并从相应方向出队！
提示：蚂蚁依次掉落的方向可以用时间的正负进行标记，我们只需按时间的绝对值对时间进行排序就能完成处理了！
*/

//用C++写自己的版本
#include <bits/stdc++.h>
#define N 100
using namespace std; //引用名字空间std
struct ant_type
{
    int pos;
    char name[11];
} ants[N];
struct event_type
{
    int drop_time;
    char dir;
} events[N];
bool cmp_ant(const ant_type &p, const ant_type &q)
{
    return p.pos < q.pos;
}
bool cmp_event(const event_type &p, const event_type &q)
{
    return p.drop_time < q.drop_time;
}

int main()
{
    char dir[2];
    int i, k, n, L, R, T;
    scanf("%d", &T);
    for (k = 1; k <= T; k++)
    {
        scanf("%d%d", &n, &L);
        for (i = 0; i < n; i++)
        {
            scanf("%s%d%s", ants[i].name, &ants[i].pos, dir);
            events[i].dir = dir[0];
            events[i].drop_time = (dir[0] == 'L' ? ants[i].pos : L - ants[i].pos);
        }
        sort(ants, ants + n, cmp_ant);
        sort(events, events + n, cmp_event);
        printf("Case #%d:\n", k);

        L = 0;
        R = n - 1;
        for (i = 0; i < n; i++)
        {
            if (events[i].dir == 'L')
            {
                printf("%d %s\n", events[i].drop_time,
                       ants[L].name);
                L++;
            }
            else
            {
                printf("%d %s\n", events[i].drop_time,
                       ants[R].name);
                R--;
            }
        }
    }
    return 0;
}