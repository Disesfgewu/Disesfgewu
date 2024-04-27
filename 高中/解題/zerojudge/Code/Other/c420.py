x = int ( input("") )
for i in range (1,x+1):
    for j in range (x-i):
        print ("_", end='')
    for j in range (2*i-1):
        print ("*" , end='')
    for j in range (x-i):
        print ("_", end='')
    print ("")