while 1 :
    try :
        x = input("").split()
    except :
        break
    for i in range( len( x ) ) :
        x[i] = int( x[i] ) 
    ans = str( pow( x[0] , x[1] ) % pow( x[2] , x[3] ) )
    r = (len( ans )-1) % 3 
    for i in range( len( ans ) ) : #-1 , 0 , -1 ) :
        print( ans[i] , end="" )
        if i % 3 == r :
            print( end=" " )
    print("")