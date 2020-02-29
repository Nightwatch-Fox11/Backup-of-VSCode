/*C++数组求和用自带的库超级方便，而且也达到代码更加简洁的目的。
only suitable for int
你只需要做2步：

1、导入库文件
#include <numeric>
2、添加空间名
using namespace std;

然后就可以直接使用 ：
accumulate(arrayName, arrayName + 数组长度, 数组起始位)

demo：
int array[6] = {1,2,3,4,5,6}；
int sum = accumulate(array, array + 6, 0)；

就这样 得到了数组的和， 是不是比用其他的方便快捷。

*/