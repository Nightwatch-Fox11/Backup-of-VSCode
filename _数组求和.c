#include <stdio.h>

int summ(int a[], int n)
{
    int sum = 0;
    for (int *p = a; p < a + n; p++)
    {
        sum += *p;
    }
    return sum;
}
int main()
{
    int a[2] = {22, 3};
    printf("%d", summ(a, 2));
}