from tkinter import *
tk = Tk()
cas = Canvas( tk , width = 300 , height = 100 )
cas.pack()
id = cas.create_oval( 10 , 10 , 30 , 30 , fill = 'red' )
print( id )
while 1 :
    cas.move( id , 2 , 0 )
    tk.update()
    cas.after( 50 )