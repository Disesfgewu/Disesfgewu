from tkinter import *
from random import *
tk = Tk()
w = 300
h = 100
cas = Canvas( tk , width = w , height = h )
cas.pack()
id = cas.create_oval( 10 , 10 , 30 , 30 , fill = 'lightblue' )
cas.move( id , w/2 , h/2 )
#print( id )
x = randint( 1 , 5 )
y = randint( 1 , 5 )
#print ( y )
while 1 :
    p = cas.coords( id )
    print ( x , end= " ")
    print( y )
    if p[0] < 0 :
        x = x * -1 
    if p[1] < 0 :
        y = y * -1
    if p[2] > w :
        x = x * -1
    if p[3] > h :
        y = y * -1
    cas.move( id , x , y )
    tk.update()
    cas.after(10)