while 1 :
    try :
        x= int(input(""))
    except :
        break
    for i in range ( x+1 ):
        print ( "2^", end="" )
        print ( i , end=" " )
        print ( "=" , end=" ")
        print ( pow( 2 , i ) )