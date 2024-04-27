while 1 :
    try :
        x = int(input())
    except:
        break
    if ( x % 3 == 0 ):
        print( "yes" )
    else:
        print("no")