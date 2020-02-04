#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string sent, word;
int lens, lenw, t, pos;
int main()
{
    getline(cin, word);
    getline(cin, sent); //字符串含有空格输入，不可以用cin，否则to me只能读到to
    lenw = word.size();
    lens = sent.size();
    for (int i = 0; i < lenw; i++)
        word[i] = toupper(word[i]); //转成大写
    for (int i = 0; i < lens; i++)
        sent[i] = toupper(sent[i]);
    t = 0;
    for (int i = 0; i <= lens - lenw; i++)
    {
        int j;
        for (j = 0; j < lenw; ++j)
        {
            if (sent[j + i] != word[j])
                break;
            if (i > 0 && sent[i - 1] != ' ')
                break; //不是单词开头就结束
        }
        if (j == lenw && (sent[j + i] == ' ' || j + i == lens)) //单词长度匹配，后面是空格或者句末
        {
            t++;
            if (t == 1)
                pos = i;
        }
    }
    if (t == 0)
        cout << -1;
    else
        cout << t << " " << pos;
    return 0;
}