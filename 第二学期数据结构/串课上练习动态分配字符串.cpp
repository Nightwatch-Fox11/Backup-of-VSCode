#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXLEN 100
typedef struct
{
    char ch[MAXLEN];
    int len;
} SeqString;

void StrInsert(SeqString *s, int pos, SeqString t, char *p)
{
    p = (char *)malloc(t.len + s->len);
    for (int i = 0; i < pos; i++)
    {
        p[i] = s->ch[i];
    }
    for (int i = 0; i < strlen(p); i++)
    {
        p[pos + i] = t.ch[i];
    }
    int a = strlen(p);
    for (int i = pos; i < s->len; i++)
    {
        p[a + i] = s->ch[i];
    }
}