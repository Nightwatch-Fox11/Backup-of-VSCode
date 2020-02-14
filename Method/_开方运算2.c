#include <stdio.h>

int Mysqrt(int n)

{

    float i;

    for (i = 3; i * i <= n; i += 0.01)

        ;

    return i - 0.01;
}

int main()

{

    printf("%.2f\n", Mysqrt(10));

    printf("%.2f\n", Mysqrt(9));

    return 0;
}
