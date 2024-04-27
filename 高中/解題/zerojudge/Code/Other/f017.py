while 1 :
    try :
        a = input()
    except :
        break
    for i in range( len(a)-1 ):
        print( a[i] + "-" , end="" )
    print( a[len(a)-1] )