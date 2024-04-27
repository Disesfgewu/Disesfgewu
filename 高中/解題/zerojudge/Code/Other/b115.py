#import sys
#for i in sys.stdin :
#   print(eval(i.replace("/", "//")))
while 1 :
    try :
        x = int(input(""))
        y = input("")
        z = int(input(""))
    except :
        break
    if y == "*" :
        print ( int( x * z ) )
    else :
        print ( int( x / z ) )