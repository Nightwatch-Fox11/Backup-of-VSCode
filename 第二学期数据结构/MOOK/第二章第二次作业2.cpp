// 带头结点的单链表L，编写算法实现就地逆置。
struct _lnklist //相关定义
{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void reverse(LinkList L) //L为头节点
{
    LinkList p = L->next, q;
    L->next = NULL;

    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}
