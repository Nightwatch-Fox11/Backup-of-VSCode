#include <stdio.h>
#include <stdlib.h>
#include "dsstring.h"

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int lenin = 0, lenold = 0, lennew = 0, t = 0;
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
    int flag = 1, start = 0;
    while (flag)
    {
        int i = start, j = 0;
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
            if (i - lenold + lennew >= outlen)
            {
                return 0;
            }
            else
            {
                t++;
                for (int k = 0; k < i - lenold; k++)
                {
                    out[i] = in[i];
                }
                for (int k = 0; k < lennew; k++)
                {
                    out[i - lenold + k] = newstr[i];
                }
                for (int k = i - lenold + lennew; k < outlen; k++)
                {
                    out[k] = in[k - lennew + lenold];
                }
                start = i - lenold + lennew;
            }
        }
        else
        {
            flag = 0;
        }
    }
    return t;
}