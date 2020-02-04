a = input().split(':')
if int(a[0]) <= 12 and int(a[0]) >= 0:
    print('Only '+a[0]+':'+a[1]+'.  Too early to Dang.')
else:
    if int(a[1]) != 0:
        for i in range(int(a[0]) - 11):
            print('Dang', end='')
    else:
        for i in range(int(a[0]) - 12):
            print('Dang', end='')
