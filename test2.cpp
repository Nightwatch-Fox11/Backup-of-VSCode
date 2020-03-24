#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct //运算数
{

    char a[MAX][MAX];

    int top;

} OPND;

void Init_OPND(OPND *s) //初始化运算数栈
{

    s->top = -1;
}

void Push_OPND(OPND *s, char x[20]) //push一个运算数
{

    s->top++;
    strcpy(&(s->a[s->top][MAX]), x);
}

void Push_OPTR(OPTR *s, char x) //push一个运算符
{

    s->top++;

    s->a[s->top] = x;
}

intfunc(int e)
{
    int i = 0, result = 0;
    for (i = 1; i <= e; i++)

    {
        result = result + i * 10;
    }
    return result;
}

int Pop_OPND(OPND *s) //pop一个运算数
{

    charx[20];

    strcpy(x, &(s->a[s->top][MAX]));
    int len = strlen(x);
    s->top--;
    int i = 0, result = 0;
    int k;
    if (len > 1)

    {
        for (i = len; i > 0; i--)

        {
            k = func(len - 1);
            result = result + (x[len - i] - '0') * k;
        }
    }
    else
    {
        int a = x[0] - '0';

        return a;
    }

    return result;
}

int Operate(int x, char opr, int y) //计算
{

    int result;

    switch (opr)

    {

    case '+':
        result = x + y;

        break;

    case '-':
        result = x - y;

        break;

    case '*':
        result = x * y;

        break;

    case '/':
        result = x / y;

        break;
    }

    return result;
}

int main(int argc, char *argv[])
{
    OPND sdata;

    Init_OPND(&sdata);

    Init_OPTR(&soper);

label:
    printf("请输入表达式：(间隔为空格)\n");
    while (1)

    {
        char a[20];
        scanf("%s", &a);
        if (a[0] != '$') //判断是不是结束符

        {
            if (a[0] == '+' || a[0] == '-' || a[0] == '*' || a[0] == '/')

            {
                //取出两个数，栈内没有运算符
                int key1 = 0, key2 = 0, result = 0;
                char s[20];
                key1 = Pop_OPND(&sdata);
                key2 = Pop_OPND(&sdata);

                result = Operate(key1, a[0], key2);
                sprintf(s, "%d", result);
                Push_OPND(&sdata, s);
            }
            else //入栈

            {
                Push_OPND(&sdata, a);
            }
        }
    }
    int key1 = 0;
    key1 = Pop_OPND(&sdata);
    printf("end = %d\n", key1);
}
