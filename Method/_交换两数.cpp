// C++引用
void swap1(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
// C指针
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}