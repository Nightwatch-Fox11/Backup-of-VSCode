#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 10000
struct node
{
    double num[MAX];
    int top;
};
int main(void)
{
    struct node *stack = (struct node *)malloc(sizeof(struct node));
    stack->top = -1;
    char expr[MAX][40];
    int i = 0;
    while (~scanf("%s", expr[i]))
    {
        ++i;
    }
    for (--i; i >= 0; --i)
    {
        if (strlen(expr[i]) == 1 && (expr[i][0] == '+' || expr[i][0] == '-' || expr[i][0] == '*' || expr[i][0] == '/'))
        {
            if (stack->top >= 1)
            {
                switch (expr[i][0])
                {
                case '+':
                    stack->num[stack->top - 1] = stack->num[stack->top] + stack->num[stack->top - 1];
                    stack->top--;
                    break;
                case '-':
                    stack->num[stack->top - 1] = stack->num[stack->top] - stack->num[stack->top - 1];
                    stack->top--;
                    break;
                case '*':
                    stack->num[stack->top - 1] = stack->num[stack->top] * stack->num[stack->top - 1];
                    stack->top--;
                    break;
                case '/':
                    if (stack->num[stack->top - 1] == 0)
                    {
                        printf("ERROR\n");
                        return 0;
                    }
                    stack->num[stack->top - 1] = stack->num[stack->top] / stack->num[stack->top - 1];
                    stack->top--;
                    break;
                }
            }
            else
            {
                printf("ERROR\n");
                return 0;
            }
        }
        else
        {
            stack->num[++(stack->top)] = atof(expr[i]);
        }
    }
    if (stack->top != 0)
    {
        printf("ERROR\n");
        return 0;
    }
    printf("%.1f\n", stack->num[0]);
    return 0;
}