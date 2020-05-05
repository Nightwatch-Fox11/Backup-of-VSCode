#include <bits/stdc++.h>
using namespace std;
//法一 模拟栈过程 un
/*
int main()
{
    stack<char> st;
    int n;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            char c = st.top();
            if (c == '(')
            {
                st.pop();
                continue;
            }
            else
            {
            }
        }
    }

    return 0;
}
*/

/*
法二： 不使用用栈，直接+1-1  AC
思路是每一次设置一个计数器cnt为0
读入 （ 就cnt++ ，读入 ） 就cnt--  
当cnt==0时遇到）则answer++
最后答案==answer+cnt（cnt相当于剩下的未匹配的括号）
*/
int main()
{
    int T, answer;
    cin >> T;
    if (!T)
    {
        cout << 0 << endl;
        return 0;
    }

    while (T--)
    {
        answer = 0;
        int n, cnt = 0;
        cin >> n;

        if (!n)
        {
            cin.get();
            cout << 0 << endl;
            continue;
        }

        string a;
        cin >> a;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '(')
            {
                cnt++;
            }
            else
            {
                if (!cnt)
                {
                    answer++;
                }
                else
                {
                    cnt--;
                }
            }
        }
        cout << answer + cnt << endl;
    }

    return 0;
}