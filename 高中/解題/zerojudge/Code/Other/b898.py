while 1 :
    try :
        x = int(input(""))
    except :
        break
    s = []
    for i in range (x) :
        a = input("").split()
        s.append(a)
    p = []
    for i in range (x) :
        p.append(0)
    for i in range (x) :
        for j in range (3):
            p[i] = max(p[i],int(s[i][j]))
        print (p[i])