a = []
a.append(1)
a.append(1)
for i in range( 2 , 51 ):
   a.append( a[i-1] + a[i-2] )
while 1 :
    try :
        n = int( input("") )
    except :
        break 
    if n == 0 :
        break
    print( a[n] )