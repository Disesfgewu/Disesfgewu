s = input("")
a = s.split()
b = len(s)
ze = 0 
one = 0 
o = 0 
p = 0
sum = 0 
for i in range(b):
    if s[i] != "0" and s[i] != "1" :
        o = o + 1
    elif s[i] == "0":
        ze = ze + 1
    elif s[i] == "1":
        one = one + 1
if b >= 3 :
    for i in range (b-2):
        if s[i] == "1" and s[i+1] == "0" and s[i+2] == "1" :
            p = p + 1 
if o > 0 :
    print ("1",end=" ")
    sum = 1
if b < 8 or b > 12 :
    print ("2",end=" ")
    sum = 1
if ze < 2 :
    print ("3",end=" ")
    sum = 1
if one < 3 :
    print ("4",end=" ")
    sum = 1
if p < 1 :
    print ("5",end=" ")
    sum = 1
if sum != 1 :
    print ("0", end=" ")
print ("")

    