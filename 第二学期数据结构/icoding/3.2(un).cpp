#include <stdio.h>
int length(char *a);
int _find(char *a, char *b, int pos);
void Delete(char *a, int pos, int len);
void insert(char *a, int pos, char *b);
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    int lenin = length(in), lenold = length(oldstr), lennew = length(newstr), m = _find(in, oldstr, 0), t = 0; //t为匹配次数
    // 统计长度
    char outt[outlen];
    for (int k = 0; k < lenin; k++)
    {
        outt[k] = in[k];
    }
    while (m && length(outt) - lenold + lennew < outlen)
    {
        Delete(outt, m, lenold);
        insert(outt, m, newstr);
        m += lennew;
        m = _find(outt, oldstr, m);
        t++;
        for (int k = 0; k < length(outt); k++)
        {
            out[k] = outt[k];
        }
    }
    return t;
}
void insert(char *a, int pos, char *b)
{
    int lena = length(a), lenb = length(b), i;
    for (i = lena + lenb - 1; i >= lenb + pos; i--)
    {
        a[i] = a[i - lenb];
    }
    for (i = 0; i < lenb; i++)
    {
        a[i + pos] = b[i];
    }
    a[lena + lenb] = '\0';
}
void Delete(char *a, int pos, int len)
{
    int lena = length(a), i;
    for (i = pos + len; i < lena; i++)
    {
        a[i - len] = a[i];
    }
    a[lena - len] = '\0';
}
int _find(char *a, char *b, int pos)
{
    int lena = length(a), lenb = length(b);
    int i = pos;
    int j = 0;
    if (pos < 0)
    {
        return 0;
    }
    while (i < lena && j < lenb)
    {
        if (a[i] == b[j])
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
    return j >= lenb ? i - lenb : 0;
}
int length(char *a)
{
    int temp = 0;
    while (a[temp] != '\0')
    {
        temp++;
    }
    return temp;
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
    int m = str_replace("aaabbbccc", l, 14, "c", "123");
    printf("%d\n%s", m, l);
    return 0;
}