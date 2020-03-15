/*      error???
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char ch = getchar();
    string a, b;
    getline(cin, a);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, b);
        for (int j = 0; a.size() <= j + b.size(); j++)
        {
            int cns = 0;
            for (int k = 0; k < a.size(); k++)
            {
                if (a[k] == b[k + j])
                {
                    cns++;
                }
                else
                {
                    cns == 0;
                }
            }
            if (cns == a.size() && (b[j + cns] == ' ' || j == b.size() - a.size()))
            {
                flag++;
                break;
            }
        }
    }
    if (flag)
    {
        cout << flag;
    }
    else
    {
        cout << "Do not find";
    }

    return 0;
}*/
/*      WA but WHY!!!!!!!  I think it's right
#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int n;
        cin >> n;
        char ch = getchar();
        getline(cin, a);
        int cns = 0;
        while (n--)
        {
            getline(cin, b);
            istringstream is(b);
            string s;

            while (is >> s)
            {
                if (a == s)
                {
                    cns++;
                }
            }
        }
        if (cns)
        {
            cout << cns << endl
                 << endl;
        }
        else
        {
            cout << "Do not find" << endl
                 << endl;
        }
    }
    return 0;
}
*/
/*     C语言版 WA!!!!!!!
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void consume(char ch)
{
    while (getchar() != ch)
        ;
}
char key[32], title[128];
int main()
{
    int T, N;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        consume('\n');
        int res = 0;
        fgets(key, 32, stdin);
        for (int i = 0; i < N; i++)
        {
            fgets(title, 128, stdin);
            bool useful = false;
            char *token = strtok(title, "  ");
            while (token != NULL)
            {
                if (strcmp(token, key) == 0)
                {
                    useful = true;
                    break;
                }
                token = strtok(NULL, " ");
            }
            if (useful)
                res++;
        }
        if (res == 0)
            printf("Do not find\n\n");
        else
            printf("%d\n\n", res);
    }
    return 0;
}
*/