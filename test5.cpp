#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<char> vi;
    string a = "32*(78-23)+78";
    for (auto c : a)
    {
        if (c == '(' || c == ')')
        {
            vi.push_back(c);
        }
    }
    if (vi.size() % 2 != 0 || vi[0] == ')')
    {
        cout << "No";
    }
    else
    {
        int flag = 1, lef = 0, rig = 0;
        for (int i = 0; i < vi.size() / 2; i++)
        {
            if (abs(vi[i] - vi[vi.size() - i - 1]) != 1)
            {
                flag = 0;
            }
            if (vi[i] == '(')
            {
                lef++;
            }
            else
            {
                rig++;
            }
        }
        if (flag == 0 || lef <= rig)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
    }
    cout << endl;

    return 0;
}