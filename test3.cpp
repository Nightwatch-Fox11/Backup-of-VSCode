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
    int lenout = lenin, i = 0;
    // BF找字串
    while (1)
    {
        int j = 0;
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
        if (j >= lenold) //已匹配到字串，此时i为子串最后一个字符下一个字符的下标
        {
        }
    } //end of while(1)
}
