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

    return 0;
}