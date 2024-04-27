import sys
for s in sys.stdin:
    print(eval(s.replace("/", "//")))
while 1 :
    try:
        x = input("")
        a = x.split()
    except:
        break
    print ( int ( eval(x)) )