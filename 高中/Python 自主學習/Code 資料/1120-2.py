from tkinter import *
tk = Tk()
tk.geometry("200x50+50+70")
def show( ) :
    btnl["text"] = e.get()
e = Entry(tk)
e.insert( 1 , str(input("")) )
b = Label(tk , text = "Hello" )
btnl = Button( tk , text = "Start" , command = show )
e.pack()
b.pack()
btnl.pack()
tk.mainloop()