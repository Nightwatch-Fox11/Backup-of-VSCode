#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    struct person
    {
        char name[20];
        int count;
    } leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};
    int n;
    cin >> n;
    char b[7];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", b);
        if (b[0] == 'L')
        {
            (leader[0].count)++;
        }
        if (b[0] == 'Z')
        {
            (leader[1].count)++;
        }
        if (b[0] == 'F')
        {
            (leader[2].count)++;
        }
    }
    cout << leader[0].name << ':' << leader[0].count << endl;
    cout << leader[1].name << ':' << leader[1].count << endl;
    cout << leader[2].name << ':' << leader[2].count << endl;

    return 0;
}