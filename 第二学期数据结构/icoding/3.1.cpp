#include "dsstring.h" //请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int str_compare(const char *ptr1, const char *ptr2)
{
    int len1 = 0, len2 = 0;
    while (ptr1[len1] != '\0')
    {
        len1++;
    }
    while (ptr2[len2] != '\0')
    {
        len2++;
    }
    for (int i = 0; i < len1 && i < len2; i++)
    {
        if (ptr1[i] != ptr2[i])
        {
            if (((ptr1[i] >= 'A' && ptr1[i] <= 'Z') || (ptr1[i] >= 'a' && ptr1[i] <= 'z')) && ((ptr2[i] >= 'A' && ptr2[i] <= 'Z') || (ptr2[i] >= 'a' && ptr2[i] <= 'z')))
            {
                char ch1, ch2;
                ch1 = (ptr1[i] >= 'A' && ptr1[i] <= 'Z') ? ptr1[i] : ptr1[i] - 32;
                ch2 = (ptr2[i] >= 'A' && ptr2[i] <= 'Z') ? ptr2[i] : ptr2[i] - 32;
                if (ch1 == ch2)
                {
                    continue;
                }

                return ptr1[i] > ptr2[i] ? 1 : -1;
            }
            else
            {
                return ptr1[i] > ptr2[i] ? 1 : -1;
            }
        }
    }
    return len1 > len2 ? 1 : -1;
}

/*   不可引用ctype
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//请不要删除，否则检查不通过
int str_compare(const char *ptr1, const char *ptr2)
{
    int len1 = 0, len2 = 0;
    while (ptr1[len1] != '\0')
    {
        len1++;
    }
    while (ptr2[len2] != '\0')
    {
        len2++;
    }
    for (int i = 0; i < len1 && i < len2; i++)
    {
        if (ptr1[i] != ptr2[i])
        {
            if (isalpha(ptr1[i]) && isalpha(ptr2[i]))
            {
                char ch1, ch2;
                ch1 = tolower(ptr1[i]);
                ch2 = tolower(ptr2[i]);
                if (ch1 == ch2)
                {
                    continue;
                }

                return ch1 > ch2 ? 1 : -1;
            }
            else
            {
                return ptr1[i] > ptr2[i] ? 1 : -1;
            }
        }
    }
    return len1 > len2 ? 1 : -1;
}
int main()
{

    char a[] = "Mi5r05U75po5286JP6mT6C5";
    char b[] = "Mi5r05U75po5286jp6MJX";
    printf("%d", str_compare(a, b));
    return 0;
}*/