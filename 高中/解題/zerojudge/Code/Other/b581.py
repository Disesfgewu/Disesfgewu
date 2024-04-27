n = int ( input("") ) 
while n :
    a = input("").split()
    count = 0 
    for i in a :
        count = count + int(i)
    print( count )
    n = n - 1 