/*以下算法是求取某带头结点的单链表的长度，请补充完整代码。

int LinkLength(LinkList L)

{

      Node* p=L->next; int i=0;

      ......           //补充此处代码

      return i;    //返回链表长度

}
*/
int LinkLength(LinkList L)
{
    Node *p = L->next;
    int i = 0;

    while (p)
    {
        p = p->next;
        i++;
    }

    return i; //返回链表长度
}