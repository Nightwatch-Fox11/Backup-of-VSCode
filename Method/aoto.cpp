#include <bits/stdc++.h>
using namespace std;
// auto 可作为一种新的for循环写法

int main()
{

    string s("hello world");
    for (auto c : s)
        c = 't';
    cout << s << endl; //结果为hello world
    for (auto &c : s)
        c = 't';
    cout << s << endl; //结果为ttttttttttt

    s = "hello world";
    for (auto &i : s)   //i是个引用 i到底引用的是什么？
        i = toupper(i); //改变成大写，影响s的值
    cout << s << endl;  //s的值是 HELLO

    s = "hello";
    for (auto i : s)    //书上说i 是char类型，那s[n]呢？
        i = toupper(i); //改变成大写，不影响s的值
    cout << s << endl;  //s的值是 hello

    return 0;
}
