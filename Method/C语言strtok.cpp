/*C 库函数 char *strtok(char *str, const char *delim) 分解字符串 str 为一组字符串，delim 为分隔符。
声明 char *strtok(char *str, const char *delim)
str -- 要被分解成一组小字符串的字符串。
delim -- 包含分隔符的 C 字符串。
该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针。

可用于分离字符串子串

*/

//eg.1
#include <string.h>
#include <stdio.h>

int main()
{
    char str[80] = "This is - www.runoob.com - website";
    const char s[2] = "-";
    char *token;

    //    获取第一个子字符串
    token = strtok(str, s);

    //   继续获取其他的子字符串
    while (token != NULL)
    {
        printf("%s\n", token);

        token = strtok(NULL, s);
    }

    return (0);
}
/*
输出为
This is
 www.runoob.com
 website
*/

//eg.2
#include <stdio.h>
#include <cstring> //strtok在cstring中

int main()
{
    char s[100] = "I Lobvr you!da";
    printf("下面显示的将是通过空格和分号和惊叹号分割产生的字符串\n");
    char *pch = strtok(s, " ;!");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ;!");
    }
    return 0;
}
/*
I
Lobvr
you
da
*/