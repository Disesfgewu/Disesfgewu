a = input("")
b = a.split()
sum = 0
for i in range( int(b[0]) , int (b[1])+ 1 ):
    i = str(i)
    c = list(i)
    s = 0 
    for j in range ( len(c) ):
        s += pow(int(c[j]),len(c))
    if s == int(i) :
        print ( i,end=' ')
        sum = sum + 1
if sum == 0 :
    print ("none")
else:
    print ("")