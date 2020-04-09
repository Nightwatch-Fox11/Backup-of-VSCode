#include <stdlib.h>
#include <stdio.h>
#include "dsstring.h" // 请不要删除，否则检查不通过
#define BLOCK_SIZE 4  // 可由用户定义的块大小
#define BLS_BLANK '#' // 用于空白处的补齐字符

typedef struct _block
{
    char ch[BLOCK_SIZE]; //块的数据域
    struct _block *next; //块的指针域
} Block;

typedef struct
{
    Block *head; // 串的头指针
    Block *tail; // 串的尾指针
    int len;     // 串的当前长度
} BLString;

bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
    int i, j, k, count;
    Block *r, *p;
    if (src.head == NULL && src.tail == NULL && src.len == 0)
    {
        return 0;
    }
    if (pos < 0 || pos >= src.len || len <= 0)
    {
        return 0;
    }
    for (count = 1, p = src.head; pos >= 4 * count; count++, p = p->next) //令p就位
    {
        ;
    }
    r = (*sub).head;
    i = 0;
    j = 0;
    k = pos % 4;
    while (i < len && (*sub).len < src.len)
    {
        if (!r)
        {
            r = (Block *)malloc(sizeof(Block));
            if (!r)
            {
                return 0;
            }
            r->next = NULL;
            if (!(*sub).head)
            {
                (*sub).head = (*sub).tail = r;
            }
            else
            {
                (*sub).tail->next = r;
                (*sub).tail = r;
            }
        }
        while (i < len && (*sub).len <= src.len)
        {
            (*r).ch[j] = (*p).ch[k];
            j = (j + 1) % 4;
            k = (k + 1) % 4;
            (*sub).len++;
            i++;
            if (!k)
            {
                p = p->next;
            }
            if (!j)
            {
                r = r->next;
                break;
            }
        }
    }

    if ((*sub).len == src.len)
    {
        (*sub).len--;
    }
    count = ((*sub).len - 1) % 4 + 1;
    while (count < 4)
    {
        (*sub).tail->ch[count++] = '#';
    }
    return 1;
}