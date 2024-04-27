from tkinter import *
tk = Tk()
tk.geometry("200x50+50+70")
def show1 ():
    ibll["text"] = str( int(eny1.get()) + int(eny2.get()))
def show2 ():
    ibll["text"] = str( int(eny1.get()) - int(eny2.get()))
def show3 ():
    ibll["text"] = str( int(eny1.get()) * int(eny2.get()))
def show4 ():
    ibll["text"] = str( int(eny1.get()) / int(eny2.get()))
def show5 ():
    ibll["text"] = str( int(eny1.get()) // int(eny2.get()))
eny1 = Entry(tk)
eny1.insert( 1 ,  "b" )
eny2 = Entry(tk)
eny2.insert( 1 , "a" )
ibll = Label(tk , text = " dairy (n.) 企鵝 " )
btnl = Button( tk , text = "+" , command =  show1 )
btn2 = Button( tk , text = "-" , command =  show2 )
btn3 = Button( tk , text = "*" , command =  show3 )
btn4 = Button( tk , text = "/" , command =  show4 )
btn5 = Button( tk , text = "//" , command =  show5 )
eny1.pack()
eny2.pack()
ibll.pack()
btnl.pack()
btn2.pack()
btn3.pack()
btn4.pack()
btn5.pack()
tk.mainloop()