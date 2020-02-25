#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;           //defination of vector
    vector<int>::iterator it; //defination of iterator
    for (int i = 0; i < 4; i++)
    {
        vi.push_back(i + 2); //similar to python's 'append'
    }
    //use of iterator
    it = vi.begin();
    for (int i = 0; i < vi.size(); i++) //法一
    {
        cout << *(it + i) << ' '; //v[i]==*(vi.begin()+i)
    }
    cout << endl;
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++) //法二
    {
        cout << *itt << ' ';
    }
    cout << endl;
    //use of clear
    vi.clear();
    cout << vi.size();
    //use of insert
    for (int i = 0; i < 4; i++)
    {
        vi.push_back(i + 2);
    }
    cout << endl;
    vi.insert(vi.begin() + 2, 200);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    //use of erase
    for (int i = 0; i < 20; i++)
    {
        vi.push_back(i + 2);
    }
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    vi.erase(vi.begin() + 3);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    vi.erase(vi.begin(), vi.begin() + 3);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    return 0;
}