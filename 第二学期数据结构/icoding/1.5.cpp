#include <stdio.h>
#include <stdlib.h>
#include "list.h" // 请不要删除，否则检查不通过

int lnk_search(LinkList L, int k, ElemType *p_ele)
{
    LinkList p = L;
    LinkList q = L;
    int i = 0;
    while (q)
    {
        i++;
        if (i <= k)
        {
            q = q->next;
        }
        else
        {
            q = q->next;
            p = p->next;
        }
    }
    if (p == NULL)
    {
        return 0;
    }
    *p_ele = p->data;
    return 1;
}
/*
设置两个指针，一个指针先出发，当两个指针的距离差为num后，开始同时移动。
这样相当于小学的追击问题。
void findData_reciprocal(LinkList List, int num)
{
	LinkList Head = List;
	LinkList Tail = List;
	int cnt = 0;
 
	while (Head)
	{
		cnt++;
		if (cnt <= num)
		{
			Head = Head->next;
		}
		else
		{
			Head = Head->next;
			Tail = Tail->next;
		}
	}
	if (Tail == NULL)
	{
		cout << "没有这个元素！"<< endl;
		return;
	}
	cout << "倒数第" << num << "位:" << Tail->data << endl;
}


递归
public static int nthtolast(ListNode head,int k) {
        if (head == null) {
            return 0;
        }
        int i = nthtolast(head.next,k) + 1;
        if (i == k) {
            System.out.println(head.val);
        }
        return i;
    }
直接返回节点的值
public static ListNode nthtolast(ListNode head,int k,IntWrapper i) {
        if (head == null) {
            return null;
        }
        ListNode node= nthtolast(head.next,k,i);
        i.value = i.value+1;
        if (i.value == k) {
            return head;
        }
        return node;
    }
 
class IntWrapper{
    public int value = 0;
}
