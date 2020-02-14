#include <iostream>
#include <cstring>
#include <cstdio>

int main()
{
    using namespace std;
    int n;
    char a[51];
    cin >> n;
    scanf("%s", a);
    for (int i = 0; i < strlen(a); i++)
    {
        a[i] = (a[i] - 'a' + n) % 26 + 'a';
    }
    printf("%s", a);

    return 0;
}