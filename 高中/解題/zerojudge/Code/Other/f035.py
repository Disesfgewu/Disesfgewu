while 1 :
    try :
        a = input("")
    except:
        break
    d = len(a)
    for i in range(d):
        if i < d-1 :
            print ( ord(a[i]) , end="_")
        else:
            print ( ord(a[i]))