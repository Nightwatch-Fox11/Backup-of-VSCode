/* Problem Description
lily的好朋友xiaoou333最近很空，他想了一件没有什么意义的事情，就是统计一篇文章里不同单词的总数。
下面你的任务是帮助xiaoou333解决这个问题。
Input
有多组数据，每组一行，每组就是一篇小文章。每篇小文章都是由小写字母和空格组成，没有标点符号，遇到#时表示输入结束。
Output
每组只输出一个整数，其单独成行，该整数代表一篇文章里不同单词的总数。
Sample Input
you are my friend
Sample Output
4 */
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int k = 0;
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
        {
            k++;
        }
        if (ch == '\n')
        {
            cout << k + 1 << endl;
            k = 0;
        }
    }
    return 0;
}