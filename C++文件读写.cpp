#include <fstream>
#include <iostream>
using namespace std;
/*
int main()
{
    // *************************写txt文件*******************************
    //ofstream OutFile;//实例一个写文件对象
    //OutFile.open("Test1.xlsx");//创建一个Test.txt文本，并且打开Test.txt文件
    ofstream OutFile("Test.txt");
    //利用构造函数创建txt文本，并且打开该文本
    OutFile
        << "This is a Test12!"; //把字符串内容"This is a Test!"，写入Test.txt文件
    OutFile.close();            //关闭Test.txt文件

    // *************************读txt文件*******************************
    ifstream readFile("Test.txt");   //readFile为自定义的名称
    char temp[1024] = {0};
    readFile >> temp;
    //遇到空格输出停止，空格后的内容无法输出，'\0'是截止符，如图3所示
    //readFile.getline(temp, 8， 0);//可以输出空格，遇到delim符号才截止。 最后一个参数0表示文本框遇到空字符（ASCLL码为32，文本框不可能有空字符）截止符。不加第三个参数0时，表示'\n'为截止符('\n'也是换行符)。如图4所示
    cout
        << temp << endl;
    readFile.close();
    return 0;
}
*/
int main() //本例为读取int
{
    int a, b, c;
    ifstream myfile("Test.txt");
    while (!myfile.eof()) //直到文件结尾
    {
        myfile >> a >> b >> c;
    }
    myfile.close();
    cout << a << " " << b << " " << c << endl;
    ofstream outfile("Test.txt", ios::app);
    if (!outfile.is_open())
        cout << "Open file failure" << endl;
    for (int i = 0; i != 10; ++i)
    {
        for (int j = 0; j != 10; ++j)
        {
            outfile << i << " " << j << " " << endl; //在Test.txt中写入结果
        }
    }
    outfile.close();

    return 0;
}