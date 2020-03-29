struct a
{
    int da;
    struct a *next;
} L, *U;

// ->运算符是对于指针而言的，  . 是对于结构体而言的
int main()
{
    L.da = 1;
    U->da = 1;
    (*U).da = 1;
    (*U).next = &L;
    L.next = U;
    return 0;
}