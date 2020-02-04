a, b, c = input().split()
a, b, c = int(a), int(b), int(c)
k = [a, b, c]
k.sort()
print(k[0], end='->')
print(k[1], end='->')
print(k[2])
