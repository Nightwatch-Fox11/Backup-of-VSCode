#include <iostream>
#include <cmath>

using namespace std;

int isprim(int k) //此处为标准判断素数方法
{
    if (k == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(k); i++) //注意sqrt（）防止超时
    {
        if (k % i == 0)
        {
            return 0;
        }
    }
    return 1;
}