while 1 :
    try :
        s = input("").split()
        x = int(input(""))
    except:
        break
    a = len(s)
    print ( s[a-x])