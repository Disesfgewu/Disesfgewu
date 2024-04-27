while 1 :
    try :
        x = input("")
    except :
        break
    y = x.split()
    if y[1] == '/' :
        print ( int(y[0]) // int(y[2]))
    else:
        print ( eval(x) )