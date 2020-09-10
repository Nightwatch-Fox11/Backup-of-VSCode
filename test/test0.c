#include <stdio.h>
#include <string.h>
int main()
{
    char test[] = "ays";
    int tess[] = {1, 2, 3, 6};
    int *p1 = tess;
    char *p2 = test;
    char k = 'm';
    char *p3 = k;
    printf("%d\n", strlen(test));
    printf("%d\n", sizeof(test));
    printf("%d\n", sizeof(tess));
    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(*p1));
    printf("%d\n", sizeof(*p2));
    printf("%d\n", sizeof(*p3));

    return 0;
}