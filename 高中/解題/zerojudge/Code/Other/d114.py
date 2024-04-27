import math
count = 1 
for i in range( 1 , 101 ):
    count *= math.factorial(i)
count = str(count)
for i in range ( len(count) ):
    print ( count[i] )