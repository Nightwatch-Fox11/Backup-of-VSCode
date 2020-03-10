class Solution
{
public:
    bool isPalindrome(string s)
    {
        int flag = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - i - 1] && abs(s[i] - s[s.size() - i - 1]) != 32)
            {
                flag = 1;
            }
        }
        if (flag)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};