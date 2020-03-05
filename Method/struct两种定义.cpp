// first way:结构标记
struct student
{
    int a;
    int b;
    int c;
} s1, s2, s[10];
struct student s3 = {1, 2, 3};
// second way:typeof
typedef struct teaa
{
    int a;
    int b;
} Te;
Te a = {4, 5};
Te b[9];