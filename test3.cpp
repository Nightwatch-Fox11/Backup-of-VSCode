#include <stdio.h>
#include <stdlib.h>

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int lenin = 0, lenold = 0, lennew = 0, t = 0; //t为匹配次数
    // 统计长度
    while (in[lenin] != '\0')
    {
        lenin++;
    }
    while (oldstr[lenold] != '\0')
    {
        lenold++;
    }
    while (newstr[lennew] != '\0')
    {
        lennew++;
    }
    int i = 0, j = 0;
    while (i < lenin && j < lenold)
    {
        if (in[i] == oldstr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    int m = (j >= lenold ? i - lenold : 0);
    char outt[outlen];
    for (int k = 0; k < lenin; k++)
    {
        outt[k] = in[k];
    }
    int lenout = lenin;
    printf("%s\n%d", outt, lenout);
}
int main()
{
    char l[120];
    str_replace("aaabbbccc", l, 14, "c", "123");

    return 0;
}
