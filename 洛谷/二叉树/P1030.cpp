//本题是已知二叉树的后序和中序求二叉树前序遍历，是很好的一道将理论转化为实践的一题，而且本题很好的运用了string类的性质
#include <bits/stdc++.h>
using namespace std;
void preorder(string midord, string postord)
{
    if (midord.size() > 0) //递归终点
    {
        char ch = postord[postord.size() - 1]; //后序的最后一个元素
        cout << ch;
        int k = midord.find(ch);
        preorder(midord.substr(0, k), postord.substr(0, k));
        preorder(midord.substr(k + 1), postord.substr(k, postord.size() - 1 - k)); //注意这里substr(k + 1)代表k+1到最后，后一个参数可以根据实例推出，是用长度得出的
    }
}
string m, n;
int main()
{
    cin >> m >> n;
    preorder(m, n);
    return 0;
}