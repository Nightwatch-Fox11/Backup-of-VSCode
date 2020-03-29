
int changdu(char s[])
{
    int count = 0, ;
    while (s[count] != '\0')
    {
        count++;
    }
    return count;
} //用于算char型数组的长度的函数。没有将最后的'\0'算进去。
int replace(char s[], char t[], char v[])
{
    int jilu, geshu = 0; //jilu这个变量用于记录t在s中出现的第一个位置。
    if (changdu(t) == changdu(v))
    {

        while (geshu < changdu(s))
        {
            if (s[geshu] == t[0])
            {
                jilu = geshu;
                break;
            }
            geshu++;
        }
        for (geshu = 0; geshu < changdu(t); geshu++)
        {
            s[jilu] = v[geshu];

            jilu++;
        }

        printf("%s", s);
        return 1;
    }

    else
    {
        printf("替换数组和被替换数组的长度不一致");
        return 0;
    }
}
int main()
{
    char s[] = "woaini";
    char c[] = "ai";
    char v[] = "si";
    printf("%d\n", replace(s, c, v));
}