bool path(BiTNode *root, BiTNode *node, Stack *s);

#define Stack_Size 50
typedef BiTNode *ElemType;
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;

void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  //x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false
BiTNode *nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q)
{
    int num1 = 0, num2 = 0;
    Stack s1, s2;
    BiTNode *Node1[100], *Node2[100];
    init_stack(&s1); //初始化栈
    init_stack(&s2);

    path(root, p, &s1); //找到两个栈的路径
    path(root, q, &s2);

    while (!is_empty(&s1)) //弹出元素，由于是先序遍历，最开始可能是不同的元素。保存到Node中，同时总数加一
        pop(&s1, &Node1[num1++]);
    while (!is_empty(&s2))
        pop(&s2, &Node2[num2++]);

    for (int i = 0; i < num1; ++i)
    { //找两个路径相同之处
        for (int j = 0; j < num2; ++j)
        {
            if (Node1[i] == Node2[j])
            {
                return Node1[i]; //找到则返回，后面都是相同的
            }
        }
    }
}