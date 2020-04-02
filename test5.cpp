void *memcpy(void *dest, const void *src, size_t count)
{
    char *tmp = (char *)dest, *s = (char *)src;

    while (count--)
        *tmp++ = *s++;

    return dest;
}

int str_replace(char *p_result, char *p_source, char *p_seach, char *p_repstr)
{

    int c = 0;
    int repstr_leng = 0;
    int searchstr_leng = 0;

    char *p1;
    char *presult = p_result;
    char *psource = p_source;
    char *prep = p_repstr;
    char *pseach = p_seach;
    int nLen = 0;

    repstr_leng = strlen(prep);
    searchstr_leng = strlen(pseach);

    do
    {
        p1 = my_strstr(psource, p_seach);

        if (p1 == 0)
        {
            strcpy(presult, psource);
            return c;
        }

        c++; //匹配子串计数加1;
        printf("结果:%s\r\n", p_result);
        printf("源字符:%s\r\n", p_source);

        // 拷贝上一个替换点和下一个替换点中间的字符串
        nLen = p1 - psource;
        memcpy(presult, psource, nLen);

        // 拷贝需要替换的字符串
        memcpy(presult + nLen, p_repstr, repstr_leng);

        psource = p1 + searchstr_leng;
        presult = presult + nLen + repstr_leng;

    } while (p1);

    return c;
}