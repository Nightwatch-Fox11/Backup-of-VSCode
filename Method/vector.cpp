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
    for (int i = 0; i < 4; i++)
    {
        cout << *(it + i) << ' '; //v[i]==*(vi.begin()+i)
    }

    return 0;
}