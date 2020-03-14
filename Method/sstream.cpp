/*
C++引入了ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含<sstream>这个头文件。

istringstream类用于执行C++风格的串流的输入操作。

ostringstream类用于执行C风格的串流的输出操作。

strstream类同时可以支持C风格的串流的输入输出操作。

istringstream的构造函数原形：istringstream::istringstream(string str); 它的作用是从string对象str中读取字符。
*/
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "i am a boy"; //istringstream 用法
    istringstream is(str);
    string s;
    while (is >> s)
    {
        cout << s << endl;
    }
}
/*
i
am
a
boy
*/

/*      string转int
string result =”10000”;
int n = 0;
stream << result;
stream >> n; //n等于10000
*/
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::istringstream
using namespace std;
int main()
{
    istringstream iss;
    string strvalues = "32 240 2 1450";

    iss.str(strvalues);

    for (int n = 0; n < 4; n++)
    {
        int val;
        iss >> val;
        cout << val << '\n';
    }
    cout << "Finished writing the numbers in: ";
    cout << iss.str() << '\n';
    return 0;
}
// swapping ostringstream objects
#include <string>   // std::string
#include <iostream> // std::cout
#include <sstream>  // std::stringstream

int main()
{

    std::stringstream ss;

    ss << 100 << ' ' << 200;

    int foo, bar;
    ss >> foo >> bar;

    std::cout << "foo: " << foo << '\n';
    std::cout << "bar: " << bar << '\n';

    return 0;
}