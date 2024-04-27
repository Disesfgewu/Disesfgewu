while 1 :
    try :
        x = input("").split()
    except :
        break
    a = int(x[0])
    b = int(x[1])*8
    if float(b/a) > 3 :
        print ("Too much")
    elif float(b/a) <= 3 and float(b/a) >= 2 :
        print ("Yes")
    else:
        print ("Not enough")