
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
/*
WA!!!!!
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
*/

int i, str_len, num, pos_num, j;
bool blstr_substr(BLString src, int pos, int len, BLString *sub)
{
    Block *p = src.head;
    Block *q;

    str_len = src.len; //printf("strlen%d",str_len);
    if (pos + len >= str_len)
        len = str_len - pos;
    else if (pos + len > str_len)
        len = str_len - pos;
    num = len / BLOCK_SIZE; //找出总节点数
    if (len % BLOCK_SIZE)
        num++;

    pos_num = (pos + 1) / BLOCK_SIZE; //找到坐标对应的节点数

    if ((pos + 1) % BLOCK_SIZE)
        pos_num++;
    //  printf("num%dposnum%d",num,pos_num);
    if (pos >= str_len || pos < 0 || len <= 0)
        return false;
    for (int i = 1; i < pos_num; i++)
        p = p->next; //找到对应的节点
    int len1 = 0;

    for (i = 0; i < num; i++)
    {
        if (i == 0)
        {
            q = (Block *)malloc(sizeof(Block));
            sub->head = q;
        }
        else
        {
            q->next = (Block *)malloc(sizeof(Block));
            q = q->next;
        }
        for (j = 0; j < BLOCK_SIZE; j++)
        {
            q->ch[j] = p->ch[pos % BLOCK_SIZE];
            pos++;
            len1++;
            if (pos % BLOCK_SIZE == 0)
                p = p->next;
            // printf("\n字符%c,j%d,len1%d",q->ch[j],j,len1);
            if (len1 >= len || pos >= str_len)
            {
                sub->len = len;
                sub->tail = q;
                q->next = NULL;
                for (j++; j < BLOCK_SIZE; j++)
                    q->ch[j] = '#';
                break;
            }
        }
    }
    return true;
}