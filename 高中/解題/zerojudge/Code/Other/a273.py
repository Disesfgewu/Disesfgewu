while 1 :
    try :
        x = input("").split()
    except :
        break
    if x[0] == '0':
        print ( "Ok!" )
    elif x[1] == '0' and x[0] != '0' :
        print ("Impossib1e!" )
    else:
        if int(x[0]) % int(x[1])  == 0 :
            print ( "Ok!" )
        else:
            print ( "Impossib1e!" )