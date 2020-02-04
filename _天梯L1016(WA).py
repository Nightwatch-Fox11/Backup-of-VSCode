n = int(input())
b = ['1', '0', 'X', '9', '8', '7', '6', '5', ' 4', '3', '2']
c = [7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2]
sum = 0
flag = 0
for i in range(n):
    k = input()
    for j in range(17):
        if k[j] == 'X':
            print(k)
            flag = 2
            break

        sum += (int(k[j]) * c[j])
    if b[(sum % 11)] != k[17] and flag != 2:
        flag = 1
        print(k)
    if flag == 2:
        flag = 1
    sum = 0
if flag == 0:
    print('All passed', end='')
