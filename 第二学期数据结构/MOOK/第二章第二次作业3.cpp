/*某一元多项式采用带头结点的单链表存储，编写算法求其导数。
函数声明：void Derivative(PolyNode *PL)
参数为一元多项式的头指针，该多项式按照幂次递增的次序排列，结果仍为PL所指的链表。*/
typedef struct PolyNode //结构体定义
{
    int coef; //系数
    int exp;  //指数
    struct PolyNode *next;
} PolyNode, *Polylist;
void Derivative(PolyNode *PL)
{
    PolyNode *p, *q, *tail, *temp;
    p = PL->next;
    while (p)
    {
        q = p->next;
        if (p->exp == 0)
        {
            PL->next = q; //指数为0的位置只可能是第一个节点
            free(p);
        }
        else
        {
            (p->coef) *= (p->exp);
            (p->exp)--;
        }
        p = q;
    }
}