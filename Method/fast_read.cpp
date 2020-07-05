// enter the following code at the first line of main
/*
ios::sync_with_stdio(false);
cin.tie(0);
*/
inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    return x * f;
}