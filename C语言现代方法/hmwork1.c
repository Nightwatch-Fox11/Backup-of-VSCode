#include<stdio.h>

int main()
{
int a, b, c;
if (a <= b)
{
    if (b <= c)
    {
        printf("the min is a");
    }
    else if(c <= a)
    {
        printf("the min is c");
    }
    
}else if (b <= c)
{
    printf("the min is b");
}




}