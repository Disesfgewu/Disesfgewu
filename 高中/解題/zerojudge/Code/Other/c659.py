while 1 :
    try :
        s = list( input().split() )
    except :
        break 
    for i in range( 1 , len(s) ) :
        print( s[i] , end=" " )
        if i != len(s) - 1 :
            print( s[0] , end=" ")
        else:
            break