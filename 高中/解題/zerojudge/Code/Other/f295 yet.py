while 1 :
    try :
        x = int(input(""))
    except :
        break
    a = []
    b = []
    for i in range (x):
        s = str(input(""))
        a.append(s)
    for i in range (x):
        s = input("").split()
        #print (s)
        b.append(s)
    for i in range (x):
        c = []
        for j in range(int(b[i][0])-1,int(b[i][1])):
            c.append(a[i][j])
            print (c)
        c.reverse()
        print (c)
        u = 0 
        for j in range(int(b[i][0])-1,int(b[i][1])):
            a[i].replace( a[i][j] , c[u] )
            u = u + 1
            print (a , "  1")
    for i in range (x):
        if i < x :
            print( a[i] , end=" " )
        else:
            print( a[i] , end="" )
    print (".")