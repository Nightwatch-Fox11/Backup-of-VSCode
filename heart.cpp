#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define I 20  //爱心的上半部分两个小半圆的半径
#define R 340 //爱心的下半部分圆弧曲线半径
int main()
{
    int i, j, e;
    int a;
    //爱心的上半部分 为两个实心半圆
    for (i = 1, a = I; i < I / 2; i++, a--)
    {
        for (j = (int)(I - sqrt((double)(I * I - (a - i) * (a - i)))); j > 0; j--)
            printf(" ");
        for (e = 1; e <= 2 * sqrt((double)(I * I - (a - i) * (a - i))); e++)
            printf("\3");
        for (j = (int)(2 * (I - sqrt((double)(I * I - (a - i) * (a - i))))); j > 0; j--)
            printf(" ");
        for (e = 1; e <= 2 * sqrt((double)(I * I - (a - i) * (a - i))); e++)
            printf("\3");
        printf("\n");
    }
    //爱心的中间一行 可以打印一些标记
    for (i = 1; i < 80; i++)
    {
        if (i == 25)
        {
            printf("         I LOVE YOU          ");
            i += 30;
        }
        printf("\3");
    }
    printf("\n");

    //爱心的下半部分 以R为半径的左右两条圆弧曲线 R设置为比较大
    for (i = 1; i <= R / 2; i++)
    {
        if (i % 2 || i % 3)
            continue; //因为R很大 两条曲线应该删去中间的一些点 这样就会更像爱心
        for (j = (int)(R - sqrt((double)(R * R - i * i))); j > 0; j--)
            printf(" ");
        for (e = 1; e <= 2 * (sqrt((double)(R * R - i * i)) - (R - 2 * I)); e++)
            printf("\3");
        printf("\n");
    }
    //以下是以time做时间变量来控制变色
    //懒得查时间变量函数 故用这种超耗cpu的算法代替
    //最好不要这么写 以下代码仅供娱乐
    long time;
    for (;;)
    {
        system("color a");
        for (time = 0; time < 99999999; time++)
            ;
        system("color b");
        for (time = 0; time < 99999999; time++)
            ;
        system("color c");
        for (time = 0; time < 99999999; time++)
            ;
        system("color d");
        for (time = 0; time < 99999999; time++)
            ;
        system("color e");
        for (time = 0; time < 99999999; time++)
            ;
        system("color f");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 0");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 1");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 2");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 3");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 4");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 5");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 6");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 7");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 8");
        for (time = 0; time < 99999999; time++)
            ;
        system("color 9");
        for (time = 0; time < 99999999; time++)
            ;
        system("color ab");
        for (time = 0; time < 99999999; time++)
            ;
        system("color ac");
        for (time = 0; time < 99999999; time++)
            ;
        system("color ad");
        for (time = 0; time < 99999999; time++)
            ;
        system("color ae");
        for (time = 0; time < 99999999; time++)
            ;
        system("color af");
        for (time = 0; time < 99999999; time++)
            ;
    }
    return 0;
}