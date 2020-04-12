#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// rand()会返回一随机数值, 范围在0至RAND_MAX 间。RAND_MAX定义在stdlib.h, 其值为2147483647。
//srand（）可用来设置rand()产生随机数时的随机数种子。通过设置不同的种子，我们可以获取不同的随机数序列。
// 可以利用srand((int)(time(NULL))的方法，利用系统时钟，产生不同的随机数种子。不过要调用time()，需要加入头文件< ctime >。
int main()
{
    srand((int)time(0)); // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < 10; i++)
    {
        cout << rand() % 100 << " ";
    }
    return 0;
}
/*
产生一定范围随机数的通用表示公式是：
要取得[0,n)  就是rand（）%n 表示 从0到n-1的数
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a; 
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1; 
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。 
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。 
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*/