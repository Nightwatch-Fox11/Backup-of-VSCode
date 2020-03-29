#include <ctype.h>
#include <iostream>
using namespace std;
int main()
{
    int a = 20;
    int c = '2';
    char b = 'Y';
    if (isalnum(c)) //该函数检查所传的字符是否是字母和数字。eg:'2' '3'
    {
        cout << "yes" << endl;
    }
    if (isalpha(c)) // 该函数检查所传的字符是否是字母。
    {
        cout << "yes" << endl;
    }
    if (iscntrl(c)) // 该函数检查所传的字符是否是控制字符。
    {
        cout << "yes" << endl;
    }
    if (isdigit(c)) // 该函数检查所传的字符是否是十进制数字。
    {
        cout << "yes" << endl;
    }
    if (islower(c)) // 该函数检查所传的字符是否是小写字母。
    {
        cout << "yes" << endl;
    }
    if (ispunct(c)) // 该函数检查所传的字符是否是标点符号字符。
    {
        cout << "yes" << endl;
    }
    if (isupper(c)) // 该函数检查所传的字符是否是大写字母。
    {
        cout << "yes" << endl;
    }
    if (isspace(c)) // 该函数检查所传的字符是否是空白字符。
    {
        cout << "yes" << endl;
    }
    cout << tolower(b) << toupper(b); //大小写转化

    return 0;
}