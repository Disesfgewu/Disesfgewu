from tkinter import *
frm = Tk()
def add() :
    ibl1["text"] = "+"
    ibl3["text"] = str( int( eny1.get() ) + int( eny2.get() ) ) 
def sub() :
    ibl1["text"] = "-"
    ibl3["text"] = str( int( eny1.get() ) - int( eny2.get() ) ) 
def mul() :
    ibl1["text"] = "*"
    ibl3["text"] = str( int( eny1.get() ) * int( eny2.get() ) ) 
def div() :
    ibl1["text"] = "/"
    ibl3["text"] = str( int( eny1.get() ) / int( eny2.get() ) ) 
def divi() :
    ibl1["text"] = "//"
    ibl3["text"] = str( int( eny1.get() ) // int( eny2.get() ) )
eny1 = Entry( frm , width = 10 )
eny1.insert( 1 , "16" )
ibl1 = Label( frm , text = " " , width = 10 )

eny2 = Entry( frm , width = 10 )
eny2.insert ( 1 , "5" )
ibl2 = Label( frm , text = " = " , width = 10 )
ibl3 = Label( frm , text = "   " , width = 10 )

btn1 = Button( frm , text = " + " , width = 10 , padx = 1 , command = add )
btn1 = Button( frm , text = " - " , width = 10 , padx = 1 , command = sub )
btn1 = Button( frm , text = " * " , width = 10 , padx = 1 , command = mul )
btn1 = Button( frm , text = " / " , width = 10 , padx = 1 , command = div )
btn1 = Button( frm , text = " // " , width = 10 , padx = 1 , command = divi )
