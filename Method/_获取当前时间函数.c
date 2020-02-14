#include <time.h>
#include <stdio.h>
int main()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = gmtime(&timep);
    /*获取当前秒*/
    /*获取当前分*/
    printf("%d:%d:%d\n", 8 + p->tm_hour, p->tm_min, p->tm_sec);       /*获取当前时,这里获取西方的时间,刚好相差八个小时*/
    printf("%d/%d/%d", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday); /*获取当前年份,从1900开始，所以要加1900*/
    system("pause");
    return 0;
}
