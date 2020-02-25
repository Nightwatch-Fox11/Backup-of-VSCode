#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> st;
    st.insert(20);
    st.insert(2);
    st.insert(6);
    st.insert(20);
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it << ' ';
    }
    cout << *(st.find(2));

    return 0;
}