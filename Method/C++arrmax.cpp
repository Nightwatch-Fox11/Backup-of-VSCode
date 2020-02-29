/*c++求数组元素最大最小值函数 no matter int or float*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 0, -20};
    cout << *max_element(a, a + 5) << endl;
    return 0;
}
// 也可以通过这种方式，修改最大值或最小值
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 0, -2}, m = 10;
    *min_element(a, a + 5) += *max_element(a, a + 5); //把最小元素和最大元素的和 赋给当前最小元素
    cout << *max_element(a, a + 5);
    return 0;
}
