#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t, n;
    char keyword[21], title[101];
    while (scanf("%d", &t) == 1)
    {
        while (t--)
        {
            while (scanf("%d", &n) == 1)
            {
                getchar();
                gets(keyword);
                int count = 0;
                while (n--)
                {
                    gets(title);
                    char *pToken = strtok(title, " ");
                    while (pToken != NULL)
                    {
                        if (strcmp(pToken, keyword) == 0)
                        {
                            count++;
                            break;
                        }
                        pToken = strtok(NULL, " ");
                    }
                }
                if (count)
                    printf("%d\n\n", count);
                else
                    printf("Do not find\n\n");
            }
        }
    }

    return 0;
}