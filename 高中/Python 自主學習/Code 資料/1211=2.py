dec = float(input("輸入數字："))
d = int( dec )
def a ( f ):
    print("轉換為二進位制為：  ", bin(d) , end="." )
    p = f 
    while p >= 1.0 :
        p = p - 1.0 
    p = p * 2.0
    print( int(p) , end="" )
    while int( p*10 ) % 10 != 0 :
        p = p * 2.0 
        print( int(p) , end="" )
    print()
def b ( f ):
    a = oct(d)
    print("轉換為八進位制為：  ", a , end="." )
    p = f 
    while p >= 1.0 :
        p = p - 1.0 
    p = p * 8.0
    print( int(p) , end="" )
    j = float( int(p) )
    p = p - j
    while int( p*10 ) % 10 != 0 :
        p = p * 8.0 
        print( int(p) , end="" )
    print()
def c ( f ):
    print("轉換為十六進位制為：", hex(d))
a(dec)
b(dec)
c(dec)
