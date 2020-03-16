#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// for_each
int main()
{
    vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    for_each(vec.begin(), vec.end(), [](int i) -> void { cout << i << " "; });

    cout << endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
// 用法二
void func(int n)
{
    std::cout << n << std::endl;
}

int main()
{
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);

    std::for_each(arr.begin(), arr.end(), func);

    return 0;
}