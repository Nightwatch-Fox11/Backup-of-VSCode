//求最长公共子序列长度问题
//首先设置两个状态参量i，j分别为串1与串2的前i，j个元素的子串。   i,j 为长度  本题中要注意与下标的转换
//那么问题就可以分解为串一的前i个字符的子串，与串二前j个字符的子串的最大公共子序列长度
//状态转移方程可以如下设置：首先设置maxlen[max][max]  max为字符串的最大长度，两个位置分别对应i，j
//maxlen[i][j] = maxlen[i-1][j-1] (s1[i]==s2[j])
//               0 (i<0||j<0)
//               max(maxlen[i-1][j],maxlen[i],[j-1])
#include <bits/stdc++.h>
using namespace std;
int maxlen[1001][1001]; //题目中串的最大长度为1000. 0号弃置， 本题中会初始化为-1代表未访问过，
string a, b;
int dp(int i, int j)
{
    if (maxlen[i][j] >= 0) //代表此种情况已考虑过
    {
        return maxlen[i][j];
    }

    if (i == 0 || j == 0)
    {
        return maxlen[i][j] = 0;
    }
    else if (a[i - 1] == b[j - 1]) //注意下标转换
    {
        return maxlen[i][j] = dp(i - 1, j - 1) + 1;
    }
    else
    {
        return maxlen[i][j] = max(dp(i - 1, j), dp(i, j - 1));
    }
}
int main()
{
    getline(cin, a);
    getline(cin, b);
    memset(maxlen, -1, sizeof(maxlen));
    cout << dp(a.size(), b.size()) << endl; //注意下标问题
    return 0;
}