//本题是已知二叉树的前序和中序求二叉树后序遍历，和1030极其相似，只是输出位置变了，以及substr的参数要微调
#include <bits/stdc++.h>
using namespace std;
void postorder(string midord, string preord)
{
    if (midord.size() <= 0)
        return;
    int k = midord.find(preord[0]);
    postorder(midord.substr(0, k), preord.substr(1, k + 1));
    postorder(midord.substr(k + 1), preord.substr(k + 1));
    cout << preord[0];
}
string m, n;
int main()
{
    cin >> m >> n;
    postorder(m, n);
    return 0;
}