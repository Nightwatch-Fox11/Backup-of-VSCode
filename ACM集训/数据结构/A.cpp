#include <bits/stdc++.h>
using namespace std;
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