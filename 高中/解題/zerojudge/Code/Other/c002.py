def f91( n ) :
    if n >= 101 :
        return n-10
    else:
        return f91( f91( n+11 ) )
while True :
    x = int( input("") )
    if x == 0 :
        break
    print( "f91(", end="" ) 
    print( x , end="")
    print( ") = " , end="" )
    print( f91(x))
    