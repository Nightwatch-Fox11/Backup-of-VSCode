#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
char *concat(const char *s1, const char *s2)
{
    char *result;
    result = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL)
    {
        cout << "Error";
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
int main()
{

    char *p = concat("YEs", " LI");

    cout << p;

    return 0;
}