#include <cstdio>
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
    while (i < lenin && j < lenold) //首次BF
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
    while (m && lenout - lenold + lennew < outlen)
    {
        for (int k = m + lenold; k < lenout; k++)
        {
            outt[k - lenold] = outt[k];
        }
        lenout -= lenold;
        outt[lenout] = '\0';
        for (int k = lenout + lennew - 1; k >= lennew + m; k--)
        {
            outt[k] = outt[k - lennew];
        }
        for (int k = 0; k < lennew; k++)
        {
            outt[k + m] = newstr[k];
        }
        m += lennew;
        lenout += lennew;
        i = m;
        j = 0;
        while (i < lenout && j < lenold)
        {
            if (outt[i] == oldstr[j])
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
        m = (j >= lenold ? i - lenold : 0);
        t++;
        for (int k = 0; k < lenout; k++)
        {
            out[k] = outt[k];
        }
        out[lenout] = '\0';
    }
    return t;
}
int main()
{
    char l[120];
    /*
    char m[20] = "IUdaHUIH";
    char u[20] = "aHU";
    printf("%d\n", length(q));
    printf("%d", _find(m, u, 0));
    Delete(m, 1, 2);
    insert(m, 1, u);
    printf("%s", m);
    */
    // int m = str_replace("abcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqrabcdefghijklmnopqr", l, 100, "pqrabcdef", "##icoding.run##");
    int m = str_replace("aaabbbccc", l, 14, "b", "123");
    printf("%d\n%s", m, l);
    return 0;
}