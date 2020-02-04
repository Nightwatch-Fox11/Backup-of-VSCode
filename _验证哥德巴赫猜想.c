/*验证歌德巴赫猜想
 任一充分大的偶数，可以用两个素数之和表示，例如：
		4 = 2 + 2
		6 = 3 + 3
     10 = 3 + 7
     10 = 5 + 5
		..
		9 8 = 1 9 + 7 9
输入一个偶数，将其表示为两素数之和，并输出*/
#include <stdio.h>

int is_prim(int n)
{
	int i = 2, m;
	if (n == 2)
	{
		return 1;
	}

	if (n >= 2)
	{
		while (i < n)
		{
			m = n % i;
			if (m == 0)
			{
				break;
			}
			i++;
		}
		if (i == n)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	int num1 = 2, num2, num;
	printf("Enter a number ");
	scanf("%d", &num);
	if (num % 2 != 0)
		printf("Not a even\n");

	else
	{
		for (; num1 <= num / 2; num1++)
		{
			if (is_prim(num1) && is_prim(num - num1))
			{
				printf("%d = %d + %d\n", num, num1, num - num1);
			}
		}
	}

	return 0;
}