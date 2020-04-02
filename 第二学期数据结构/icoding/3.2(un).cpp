#include <stdio.h>
#include <stdlib.h>

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int lenin = 0, lenold = 0, lennew = 0, t = 0;
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
        if (j >= lenold)
        {

            if (lenout + lennew >= outlen)
            {
                out[lenout + 1] = '\0';
                return t;
            }
            else
            {
                if (t == 0)
                {
                    for (int k = 0; k < i - lenold; k++)
                    {
                        out[k] = in[k];
                    }
                    lenout = i - lenold;
                }
                for (int k = 0; k < lennew; k++)
                {
                    out[lenout + k] = newstr[k];
                }
                lenout += lennew;
                for (int k = 0; k + i < lenin; k++)
                {
                    if (lenout + k == outlen - 1)
                    {
                        out[outlen - 1] = '\0';
                        break;
                    }

                    out[lenout + k] = in[i + k];
                }

                t++;
            }
        }
        else
        {
            break;
        }
    }
    return t;
}