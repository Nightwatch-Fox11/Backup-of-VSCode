#include <stdio.h>
int length(const char *a)
{
    int temp = 0;
    while (a[temp] != '\0')
    {
        temp++;
    }
    return temp;
}
void insert(char *a, int pos, const char *b)
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
int _find(const char *a, const char *b, int pos)
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
/*
#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>

int length(char* a)
{
    int temp = 0;
    while (a[temp] != '\0') {
        temp++;
    }
    return temp;
}
int _find(char* a, char* b, int pos)
{
    int lena = length(a), lenb = length(b);
    int i = pos;
    int j = 0;
    if (pos < 0) {
        return 0;
    }
    while (i < lena && j < lenb) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    return j >= lenb ? i - lenb : 0;
}
void Delete(char* a, int pos, int len)
{
    int lena = length(a), i;
    for (i = pos + len; i < lena; i++) {
        a[i - len] = a[i];
    }
    a[lena - len] = '\0';
}
void insert(char* a, int pos, char* b)
{
    int lena = length(a), lenb = length(b), i;
    for (i = lena + lenb - 1; i >= lenb + pos; i--) {
        a[i] = a[i - lenb];
    }
    for (i = 0; i < lenb; i++) {
        a[i + pos] = b[i];
    }
    a[lena + lenb] = '\0';
}

int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr)
{
    int lenin = length(in), lenold = length(oldstr), lennew = length(newstr), m = _find(in, oldstr, 0), t = 0; //t为匹配次数
    // 统计长度
    char outt[outlen];
    for (int k = 0; k < lenin; k++) {
        outt[k] = in[k];
    }
    while (m && length(outt) - lenold + lennew < outlen) {
        Delete(outt, m, lenold);
        insert(outt, m, newstr);
        m += lennew;
        m = _find(outt, oldstr, m);
        t++;
        for (int k = 0; k < length(outt); k++) {
            out[k] = outt[k];
        }
    }
    return t;
}
*/

#include "dsstring.h"
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr)
{
    char *c = out;
    while (*(c++) = *(in++))
        ;
    c = out;
    int len, len2, flag = 1, i = 0, j = 0, len3, endp = 0, cnt = 0;
    for (len = 0; c[len] != '\0'; ++len)
        ;
    for (len2 = 0; oldstr[len2] != '\0'; ++len2)
        ;
    for (len3 = 0; newstr[len3] != '\0'; ++len3)
        ;
    for (i = 0; i < len; ++i)
    {
        flag = 1;
        for (j = 0; j < len2; ++j)
        {
            if (i + j < outlen - 1 && c[i + j] != oldstr[j])
            {
                flag = 0;
                break;
            }
            else if (i + j > outlen - 2)
            {
                flag = -1;
                break;
            }
        }
        if (flag == 1 && i + len3 > outlen - 1)
            flag = -1;
        if (flag == 1)
        {
            if (len2 <= len3)
            {
                for (j = min(outlen - 2, len - 1 + len3 - len2); j >= i + len3; --j)
                {
                    c[j] = c[j - len3 + len2];
                }
                endp = min(outlen - 2, len - 1 + len3 - len2);
            }
            else
            {
                for (j = i + len3; j <= len - 1 - len2 + len3; ++j)
                {
                    c[j] = c[j + len2];
                }
                endp = len - 1 - len2 + len3;
            }
            for (j = 0; j < len3; ++j)
            {
                if (i + j > outlen - 2)
                {
                    flag = -1;
                    break;
                }
                c[i + j] = newstr[j];
            }
            cnt++;
            len = endp + 1;
            c[len] = '\0';
            i = i + len3 - 1;
        }
        if (flag == -1)
        {
            break;
        }
    }
    return cnt;
}