#include <stdio.h>

int main()
{
    char str[100], ch;
    int i = 0;
    printf("Enter a message ");
    while ((ch = getchar()) != '\n')
    {
        *(str + i++) = ch;
    }
    printf("Reversal is ");
    for (i -= 1; i >= 0;)
    {
        printf("%c", *(str + i--));
    }
}