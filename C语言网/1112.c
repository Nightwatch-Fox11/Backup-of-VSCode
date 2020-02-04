/*解一元二次方程ax^2+bx+c=0的解。
输入a,b,c的值。输出两个解，按照大小顺序输出，一个解时需要打印两次，不用考虑无解问题，保留两位小数
样例输入
1 5 -2
样例输出
0.37 -5.37*/

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    float x1, x2;
    scanf("%d%d%d", &a, &b, &c);
    x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    printf("%2.2f %2.2f", x1, x2);
}