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
    int i = 0, lenout, pre; //i为起始位置
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
            if (!t) //t==0即为第一次匹配成功
            {
                if (lenin - lenold + lennew > outlen)
                {
                    for (int k = 0; k < lenin; k++)
                    {
                        out[k] = in[k];
                    }
                    out[lenin] = '\0';
                    return 0;
                }
                else
                {
                    for (int k = 0; k < i - lenold; k++)
                    {
                        out[k] = in[k];
                    }
                    lenout = i - lenold;
                    for (int k = 0; k < lennew; k++)
                    {
                        out[lenout + k] = newstr[k];
                    }
                    lenout += lennew;
                    pre = lenout;
                    for (int k = 0; k + i < lenin; k++)
                    {
                        out[lenout + k] = in[i + k];
                    }
                    lenout = lenin - lenold + lennew;
                }
            }
            else //再次匹配成功
            {
                if (lenout + lennew - lenold > outlen)
                {
                    return t;
                }
                else
                {
                    for (int k = 0; k < lennew; k++)
                    {
                        out[pre + k] = newstr[k];
                    }
                    //from here
                    pre += lennew;
                    for (int k = 0; k + i < lenin; k++)
                    {
                        out[pre + k] = in[i + k];
                    }
                    lenout = lenout - lenold + lennew;
                    out[lenout] = '\0';
                }
            }
            t++;
        } //endl of 查找子串
        else
        {
            out[lenout] = '\0';
            return t;
        }
    } //end of while(1)
}
int main()
{
    char l[120];
    int m = str_replace("abcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqr", l, 100, "pqrabcdef", "##icoding.run##");
    printf("%s\n%d", l, m);
    return 0;
}
/*
串为“aaabbbccc”(长度为9)，需要将子串“b”替换为“123”，out 所占空间为 14
str_replace 函数返回值应该“3”，但现在是“2”，请修改。
str_replace 函数所得到的子串从第“9”处应该是“123c”，但现在是“bccc”，请修改。

串为“aaabbbccc”(长度为9)，需要将子串“cc”替换为“1234567”，out 所占空间为 14
str_replace 函数返回值应该“1”，但现在是“0”，请修改。
str_replace 函数所得到的子串从第“6”处应该是“1234567”，但现在是“ccc”，请修改。

串为“abcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqr”(长度为72)，需要将子串pqrabcdef替换为##icoding.run##，out 所占空间为 100
str_replace 函数所得到的子串从第“30”处应该是“ghijklmno##icoding.run##ghijklmno##icoding.run##ghijklmnopqr”，但现在是“##icoding.run####icoding.run##ghijklmnopqrpqrpqr”，请修改。
*/