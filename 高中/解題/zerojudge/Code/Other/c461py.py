while 1 :
    try :
        s = input("").split()
    except :
        break
    #print( "ghjk" )
    a = []
    for i in range( len(s) ) :
        a.append( int(s[i]) )
    #print( a )
    count = 0 
    if a[2] == 0 :
        if a[0] == 0 or a[1] == 0 :
            print( "AND" )
            count = 1
        if a[0] == 0 and a[1] == 0 :
            print( "OR" )
            count = 1
        if ( a[0] == 0 and a[1] == 0 ) or ( a[0] != 0 and a[1] != 0 ) :
            print( "XOR")
            count = 1
    else :
        if a[0] != 0 and a[1] != 0 :
            print( "AND" )
            count = 1
        if a[0] != 0 or a[1] != 0 :
            print( "OR" )
            count = 1
        if ( a[0] != 0 and a[1] == 0 ) or ( a[0] == 0 and a[1] != 0 ) :
            print( "XOR" )
            count = 1
    if count == 0 :
        print( "IMPOSSIBLE" )