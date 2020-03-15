#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
    // 前缀0表示八进制 前缀0x表示十六进制 不带前缀表示十进制
    int a = 123;
    double pi = 22.0 / 7.0;

    // setbase(n) 设置整数为n进制(n=8,10,16)
    // oct 八进制 dec 十进制 hex 十六进制
    // setiosflags(ios::showbase) 显示进制的前缀
    // 数值默认十进制显示输出
    cout << a << endl;
    cout << "oct: " << showbase << setbase(8) << a << " " << oct << a << endl;
    cout << "dec: " << showbase << setbase(10) << a << " " << dec << a << endl;
    cout << "hex: " << showbase << setbase(16) << a << " " << hex << a << endl;

    // setprecision(n) 设置浮点数的有效数字为n位
    // 有效位数默认是6位，即setprecision(6)，即小数点前面和小数点后面加起来的位数为6个有效数字（注意会四舍五入）
    cout << pi << endl;
    cout << setprecision(12) << pi << endl;

    // setfill(n) 设置字符填充，c可以是字符常或字符变量
    // setw(n) 设置字段宽度为n位, 若是实际宽度大于被设置的，则setw函数此时失效, 只针对其后的第一个输出项有效
    // setiosflags(ios::left) 输出左对齐
    // setiosflags(ios::right) 输出右对齐 默认右对齐
    cout << setfill('*') << setw(20) << setprecision(12) << pi << endl;
    cout << setfill('*') << setw(20) << setprecision(12) << right << pi << endl;
    cout << setfill('*') << setw(20) << setprecision(12) << left << pi << endl;

    // setiosflags(ios::fixed) 设置浮点数以固定的小数位数显示
    cout << fixed << setprecision(12) << pi << endl;

    // setiosflags(ios::scientific)  设置浮点数以科学计数法表示 科学计数法输出E与十六进制输出默认是以小写的，要换成大写需添加uppercase
    cout << scientific << setprecision(12) << pi << endl;
    cout << scientific << uppercase << setprecision(12) << pi << endl;

    // resetiosflags() 终止已经设置的输出格式状态，在括号中应指定内容
    cout << setiosflags(ios::scientific) << setprecision(12) << pi << "   " << resetiosflags(ios::scientific) << pi << endl;

    return 0;
}