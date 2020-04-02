#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>  //因为用了sort()函数
#include <functional> //因为用了greater<int>()
using namespace std;

int main()
{
    //对于数组
    int a[] = {3, 1, 4, 2, 5};
    int i;
    int len = sizeof(a) / sizeof(int); //这里切记要除以sizeof(int)!

    sort(a, a + len, greater<int>()); //内置类型的由大到小排序
    for (i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << "\n";
    sort(a, a + len, less<int>()); //内置类型的由小到大排序
    for (i = 0; i < len; i++)
        cout << a[i] << " ";
    //对于vector
    int A[] = {1, 4, 3, 7, 10};
    const int N = sizeof(A) / sizeof(int);
    vector<int> vec(A, A + N);
    ostream_iterator<int> output(cout, " ");
    cout << "Vector vec contains:";
    copy(vec.begin(), vec.end(), output);

    cout << "\nAfter greater<int>():";
    sort(vec.begin(), vec.end(), greater<int>()); //内置类型从大到小
    copy(vec.begin(), vec.end(), output);

    cout << "\nAfter less<int>():";
    sort(vec.begin(), vec.end(), less<int>()); //内置类型小大到大
    copy(vec.begin(), vec.end(), output);
    return 0;
}