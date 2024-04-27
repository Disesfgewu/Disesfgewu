import math
while 1 :
    try :
        x = int( input(""))
    except :
        break
    p = math.pi * pow( 10 , x )
    print( int(p%10) )