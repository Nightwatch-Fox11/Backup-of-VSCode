a = input()
k = 0
for i in a:
    if i == '2':
        k += 1
index = 1
if a[0] == '-':
    index *= 1.5
if not int(a[-1]) % 2:
    index *= 2
if a[0] == '-':
    index *= (k / (len(a) - 1) * 100)
else:
    index *= (k / len(a) * 100)
print("{:.2f}".format(index), end='')
print('%', end='')
