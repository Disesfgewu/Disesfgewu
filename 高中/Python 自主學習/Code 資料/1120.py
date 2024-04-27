from tkinter import *
tk = Tk()
tk.geometry("200x50+50+70")
def show ():
    tk.title("OK")
btnl = Button( tk , text = "Start" , command =  show )
btnl.pack()
tk.mainloop()