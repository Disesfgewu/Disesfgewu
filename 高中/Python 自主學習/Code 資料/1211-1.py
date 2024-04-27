from tkinter import *
def enter(e):
    tk.title('滑鼠進入中')
def leave(e):
    tk.title('滑鼠離開中')
tk = Tk()
tk.geometry("250x100+50+70")
ibll = Label(tk,text="Hello",bg = "red" )
ibll.place( x = 20 , y = 10 , width = 100 , height = 60 )
ibll.bind('<Enter>' , enter )
ibll.bind('<Leave>' , leave )
tk.mainloop()