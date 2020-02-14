#include <stdio.h>

#include <math.h>

int Mysqrt(int n)

{
    return sqrt(n * 1.0);
}

int main()

{

    printf("%d\n", Mysqrt(10));

    printf("%d\n", Mysqrt(9));

    return 0;
}
