#include <iostream>
#include <algorithm>

struct student
{
    char id[13];
    int goal;
    int rank;
} list[300];

bool cmp(student a, student b)
{
    for (int i = 0; i < n; i++)
    {
        /* code */
    }
}

int main()
{
    using namespace std;
    struct student
    {
        char id[13];
        int goal;
    } list[300];
    int n, k, j = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        sum += k;
        for (; j < k; j++)
        {
            cin >> list[j].id >> list[j].goal;
        }
    }

    return 0;
}