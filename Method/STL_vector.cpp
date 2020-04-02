#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //int型vector,定义了3个整型元素的向量，但没有给出初值，其值是不确定的。
    vector<int> vecIntA(3);

    //int型vector,包含3个元素且每个元素都是9
    vector<int> vecIntB(3, 9);

    //复制vecIntB到vecIntC
    vector<int> vecIntC(vecIntB);

    int iArray[] = {2, 4, 6};
    //从数组中获得初值创建vecIntD
    vector<int> vecIntD(iArray, iArray + 3);

    vector<int> vi;           //defination of vector
    vector<int>::iterator it; //defination of iterator
    for (int i = 0; i < 4; i++)
    {
        vi.push_back(i + 2); //similar to python's 'append'
    }
    //use of iterator
    it = vi.begin();
    for (int i = 0; i < vi.size(); i++) //法一
    {
        cout << *(it + i) << ' '; //v[i]==*(vi.begin()+i)
    }
    cout << endl;
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++) //法二
    {
        cout << *itt << ' ';
    }
    cout << endl;
    //use of clear
    vi.clear();
    cout << vi.size();
    //use of insert
    for (int i = 0; i < 4; i++)
    {
        vi.push_back(i + 2);
    }
    cout << endl;
    vi.insert(vi.begin() + 2, 200);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    //use of erase
    for (int i = 0; i < 20; i++)
    {
        vi.push_back(i + 2);
    }
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    vi.erase(vi.begin() + 3);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;
    vi.erase(vi.begin(), vi.begin() + 3);
    for (vector<int>::iterator itt = vi.begin(); itt != vi.end(); itt++)
    {
        cout << *itt << ' ';
    }
    cout << endl;

    // 其他不常用的
    vector<int> a, c;
    int i, b[10];
    a.assign(c.begin(), c.begin() + 3);    //c为向量，将c的0~2个元素构成的向量赋给a
    a.assign(4, 2);                        //是a只含4个元素，且每个元素为2
    a.back();                              //返回a的最后一个元素
    a.front();                             //返回a的第一个元素
    a[i];                                  //返回a的第i个元素，当且仅当a[i]存在
    a.clear();                             //清空a中的元素
    a.empty();                             //判断a是否为空，空则返回ture,不空则返回false
    a.pop_back();                          //删除a向量的最后一个元素
    a.erase(a.begin() + 1, a.begin() + 3); //删除a中第1个（从第0个算起）到第2个元素，
                                           //也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+3（不包括它）
    a.insert(a.begin() + 1, 5);            //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
    a.insert(a.begin() + 1, 3, 5);         //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
    a.insert(a.begin() + 1, b + 3, b + 6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6）,
                                           //如b为1,2,3,4,5,9,8，插入元素后为1,4,5,9,2,3,4,5,9,8
    a.capacity();                          //返回a在内存中总共可以容纳的元素个数
    a.resize(10);                          //将a的现有元素个数调至10个，多则删，少则补，其值随机
    a.resize(10, 2);                       //将a的现有元素个数调至10个，多则删，少则补，其值为2
    a.reserve(100);                        //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.
                                           // 这种操作只有在需要给a添加大量数据的时候才显得有意义，因为这将避免内存多次容量扩充操作
                                           //（当a的容量不足时电脑会自动扩容，当然这必然降低性能）
    a.swap(c);                             //c为向量，将a中的元素和c中的元素进行整体性交换
    a == c;                                //c为向量，向量的比较操作还有!=,>=,<=,>,<

    //几种重要算法   使用时需要包含头文件：#include<algorithm>
    sort(a.begin(), a.end());                //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
    reverse(a.begin(), a.end());             //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
    copy(a.begin(), a.end(), c.begin() + 1); //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素复制到c中，从c.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
    find(a.begin(), a.end(), 10);            //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置

    return 0;
}