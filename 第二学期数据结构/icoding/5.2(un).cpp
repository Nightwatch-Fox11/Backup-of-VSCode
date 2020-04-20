#include <stdlib.h>
#include <stdio.h>
#define Stack_Size 50
typedef BiTNode *ElemType;
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;
typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} BiTNode, *BiTree;
void visit_node(BiTNode *node);
void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  //x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false

bool path(BiTNode *root, BiTNode *node, Stack *s)
{
    init_stack(s);
    BiTree p = root, q = NULL;
    while (p != NULL || !is_empty(s))
    {
        while (p != NULL)
        {
            push(s, p);
            p = p->left;
        }
        if (!is_empty(s))
        {
            top(s, &p);
            if (p->right == NULL || p->right == q)
            {
                if (p == node)
                {
                    return true;
                }
                else
                {
                    pop(s, &q);
                    p = NULL;
                }
            }
            else
            {
                p = p->right;
            }
        }
    }
    return false;
}