x, y = input().split()
x = int(x)
if not x % 2:
    for i in range(x//2):
        for j in range(x):
            print(y, end='')
        print('')
else:
    for i in range(x // 2 + 1):
        for j in range(x):
            print(y, end='')
        print('')
