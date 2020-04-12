#include <iostream>
#include <limits>
#include <climits>
using namespace std;
int main()
{
    /*
    法一使用#include <limits>
    cout << numeric_limits<int>::max() << endl;
    cout << std::numeric_limits<double>::max() << endl;
    */
    /*
    法二使用#include <climits>
    cout << INT_MAX;
    */
    cout << int(((unsigned int)(~0)) >> 1); //法三~0把所有位变为1，转换乘无符号数，确保右移是逻辑右移，
                                            //也就是高位会因为右移空出个0，这样就作出一个最高位（符号位）为0其他位都为1的整数了
    return 0;
}
/*
可以算一下 0x7FFFFFFF 是多少
每个十六进制数4bit，因此8位16进制是4个字节，刚好是一个int整型（好像一个字节是8 bit）
F的二进制码为 1111
7的二进制码为 0111
这样一来，整个整数 0x7FFFFFFF 的二进制表示就是除了首位是 0，其余都是1
就是说，这是最大的整型数 int（因为第一位是符号位，0 表示他是正数）
用 INT_MAX 常量可以替代这个值。
所以目测0x好像是表示这是一个十六进制数。
相应的最小值可以表示成0x80000000或INT_MIN，这里注意一个问题就是INT_MAX和INT_MIN都被包含在一个叫<climits>的头文件中，
这个头文件用法如下：
<climits>头文件定义的符号常量
CHAR_MIN 　　　　　　char的最小值
SCHAR_MAX 　　　　　signed char 最大值
SCHAR_MIN 　　　　　 signed char 最小值
UCHAR_MAX 　　　　　unsigned char 最大值
SHRT_MAX 　　　　　　short 最大值
SHRT_MIN　　　　　　 short 最小值
USHRT_MAX　　　　　 unsigned short 最大值
INT_MAX　　　　　　　int 最大值
INT_MIN 　　　　　　　int 最小值
UINT_MAX 　　　　　　unsigned int 最大值
UINT_MIN 　　　　　　unsigned int 最小值
LONG_MAX　　　　　　long最大值
LONG_MIN 　　　　　　long最小值
ULONG_MAX 　　　　　unsigned long 最大值
FLT_MANT_DIG　　　　float 类型的尾数
FLT_DIG　　　　　　　 float 类型的最少有效数字位数
FLT_MIN_10_EXP　　　带有全部有效数的float类型的负指数的最小值（以10为底）
FLT_MAX_10_EXP 　　 float类型的正指数的最大值（以10为底）
FLT_MIN 　　　　　　　保留全部精度的float类型正数最小值
FLT_MAX　　　　　　　 float类型正数最大值
关于0x80000000，其实是负数的存储方式也就是补码，查了有关介绍记在下面：
计算机中的负数是以其补码形式存在的 补码=原码取反+1
一个字节有8位 可以表示的数值范围在 -128到+127
用二进制表示也就是 10000000 - 01111111（注意：最高位表示符号）
最高位是1的都是负数 最高位是0的都是正数
如-7 原码是 10000111 然后取反（最高位是符合不用取反）得11111000
加一 得11111001 那么-7的二进制数就是 11111001
再如 -10 原码是 10001010 取反得 11110101 加一得 11110110
那么-10的二进制数就是 11110110
二进制数是逢二进一 只有0和1两个数字 没有2
*/