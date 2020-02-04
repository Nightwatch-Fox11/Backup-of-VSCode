#include <stdio.h>

int solve(int *arr, int n, int x)
{
    const int threshold = arr[x - 1] - 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += (threshold < arr[i]) ? arr[i] - threshold : 0;
    --ans;
    return ans;
}

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve(a, n, b));
    return 0;
}
