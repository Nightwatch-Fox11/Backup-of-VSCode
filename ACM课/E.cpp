#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int m1[10] = {0}, m2[10] = {0};
    for (int i = 0; i < n; i++)
    {
        string a;
        int j;
        cin >> a;
        for (j = 0; j < a.size(); j++)
        {
            m1[a[j] - 48]++;
        }
        cin >> a;
        for (j = 0; j < a.size(); j++)
        {
            m2[a[j] - 48]++;
        }
        for (j = 0; j < 10; j++)
        {
            m1[j] -= m2[j];
        }
        int flag = 1, zh = 0, fu = 0;
        for (j = 0; j < 10; j++)
        {
            if (m1[j] > 0)
            {
                zh = 1;
            }
            if (m1[j] < 0)
            {
                fu = 1;
            }
        }
        if (fu * zh)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
        memset(m1, 0, sizeof(m1));
        memset(m2, 0, sizeof(m2));
    }

    return 0;
}
/*
for (j = 0; j < 10; j++)
        {
            if (m1[j] != m2[j])
            {
                cout << "No" << endl;
                memset(m1, 0, sizeof(m1));
                memset(m2, 0, sizeof(m2));
                break;
            }
        }
        if (j == 10)
        {
            cout << "Yes" << endl;
            memset(m1, 0, sizeof(m1));
            memset(m2, 0, sizeof(m2));
        }*/