//Toll
#include <bits/stdc++.h>
using namespace std;
int map[55][55], tot; //因为总共26+26个字母，也就是图中最多52个节点，所以这里设为55. tot
int turn(char x)
{
    return (x < 'a' ? x - 'A' + 1 : x - 'a' + 27); //将图中字母节点转化为数字节点
}
int dij(int from, int to, int o) //此题的改进版Dijkstra算法，调用一次函数就相当于进行一次Dijkstra
{
    int dis[55] = {0}, flag[55] = {0};
}
int main()
{

    return 0;
}
