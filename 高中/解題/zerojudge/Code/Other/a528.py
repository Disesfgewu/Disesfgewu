while 1 :
    try:
        x = int( input(""))
    except :
        break
    a = []
    for i in range ( x ) :
        a.append(input(""))
    for i in range ( x ):
        a[i] = int( a[i] )
    b = sorted(a)
    for i in range( x ) :
        print ( b[i] )