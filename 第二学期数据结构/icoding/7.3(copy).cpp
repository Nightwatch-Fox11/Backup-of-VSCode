#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;

//向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
node_t *Insert(node_t *T, int X);
int GetHeight(node_t *T);
int Max(int a, int b);
node_t *SingleLeftRotation(node_t *A);
node_t *DoubleLeftRightRotation(node_t *A);
node_t *SingleRightRotation(node_t *A);
node_t *DoubleRightLeftRotation(node_t *A);

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(node_t *T)
{
    if (T)
        return T->height;
    else
        return 0;
}

node_t *SingleLeftRotation(node_t *A) //左单旋
{
    node_t *B;
    B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    return B;
}

node_t *DoubleLeftRightRotation(node_t *A) //左右双旋
{
    A->left = SingleRightRotation(A->left);
    return SingleLeftRotation(A);
}

node_t *SingleRightRotation(node_t *A) //右单旋
{
    node_t *B;
    B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    return B;
}

node_t *DoubleRightLeftRotation(node_t *A) //右左双旋
{
    A->right = SingleLeftRotation(A->right);
    return SingleRightRotation(A);
}

node_t *avl_insert(node_t *root, int val)
{
    node_t *parentNode = NULL;
    if (!root)
    {
        root = (node_t *)malloc(sizeof(node_t));
        root->left = root->right = root->parent = NULL;
        root->val = val;
        root->height = 1;
    }
    else if (val < root->val)
    {
        parentNode = root->left;
        root->left = avl_insert(root->left, val);
        if (GetHeight(root->left) - GetHeight(root->right) == 2)
        {
            if (val < root->left->val)
                root = SingleLeftRotation(root);
            else
            {
                root = DoubleLeftRightRotation(root);
            }
        }
    }
    else if (val > root->val)
    {
        parentNode = root->left;
        root->right = avl_insert(root->right, val);
        if (GetHeight(root->right) - GetHeight(root->left) == 2)
        {
            if (val > root->right->val)
                root = SingleRightRotation(root);
            else
                root = DoubleRightLeftRotation(root);
        }
    }
    root->parent = parentNode;
    root->height = Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    return root;
}
