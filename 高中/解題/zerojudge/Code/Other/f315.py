n = int( input("") )
l = []
s = []
for i in range ( n ):
    l.append(s)
h = 0 
a = input("").split()
for i in range ( 2 * n ):
    a[i] = int(a[i])
    l[a[i]-1].append(a[i])
    for j in range(a[i],n):
        if l[j] == 1 :
            h = h + 1
print ( h )