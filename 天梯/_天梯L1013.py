import math
x = int(input())
sum = 0
for i in range(1, x + 1):
    sum += math.factorial(i)
print(sum, end='')
