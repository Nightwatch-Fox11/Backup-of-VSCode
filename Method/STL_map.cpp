#include <iostream>
#include <string>
#include <map>
using namespace std;
//映射
int main()
{
    map<char, int> mp;
    mp['a'] = 20;
    mp['k'] = 88;
    mp['b'] = 2;
    char a = 'p';
    int b = 9;
    mp[a] = b;
    for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << ' ' << it->second << endl;
    }
    map<int, int> mpp;
    mpp[1]++; //mpp[i]似乎在定义后自动初值0
    cout << mpp[1] << endl
         << mpp.size(); //1 1
    return 0;
}