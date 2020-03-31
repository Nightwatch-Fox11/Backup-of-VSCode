#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin >> a; //若此时输入a后回车，那么最后面的分隔符是残留在缓冲区的，cin>>不做处理。
    //也就是若下一行是getline则getline直接读入回车,无法正确读取要输入的字符串，此时需要吸收回车

    char c;
    char b;
    c = cin.get(); //这里使用cin读入一个字符，但输入c回车后b则会读取到回车，因此这两种写法可以代替getchar吸收回车
    cin.get(b);
    cout << c << b << endl;

    char array[20] = {NULL};
    cin.get(array, 20); //此处为cin读入一行的做法，不过不可读入空格，同样最后输入的回车会被c吸收掉，
    cin.get(c);         //而且cin.get读入行时只适用于C的char数组。不适用于string
    cout << array << " " << (int)a << endl;

    char brray[20] = {NULL}; //cin.getline与cin.get的区别是，cin.getline不会将结束符或者换行符残留在输入缓冲区中。
    cin.getline(brray, 20);  //或者指定结束符，如cin.getline(array,20,'\n');
    //此处无需吸收回车
    cout << brray << endl;
    return 0;
}