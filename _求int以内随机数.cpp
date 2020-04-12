#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    ofstream outfile("Tes.txt", ios::app);
    if (!outfile.is_open())
        cout << "Open file failure" << endl;
    srand((int)time(0)); // 产生随机种子  把0换成NULL也行
    for (int i = 0; i < 1000; i++)
    {
        int k = rand() % INT_MAX;
        outfile << k << endl;
    }
    outfile.close();
    return 0;
}