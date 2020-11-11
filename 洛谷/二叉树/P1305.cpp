//一开始以为是建树，但是其实是前序遍历，此题显示出认真审题并思考的重要性，本质就是给了每个节点的前三个节点的前序遍历，然后组合成一棵树的前序遍历，只要在主串中找子树的根节点并替换就行
#include <bits/stdc++.h>
using namespace std;
int n;
string a, aa;
int main()
{
    cin >> n >> a; //输入n以及主串
    for (int i = 2; i <= n; i++)
    {
        cin >> aa;
        int k = a.find(aa[0]);
        a.erase(k, 1);
        a.insert(k, aa);
    }
    for (auto i : a)
    {
        if (i != '*')
            cout << i; //这样直接输出不为*的节点
    }

    return 0;
}