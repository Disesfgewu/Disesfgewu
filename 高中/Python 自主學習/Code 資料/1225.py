from tkinter import *
from random import *
class Ball :
    sx = randint( 1 , 5 )
    sy = randint( 1 , 5 )
    x = 0
    y = 0
    def __init__( self , cas , color , winx , winy ):
        self.cas = cas
        self.id = cas.create_oval( 10 , 10 , 30 , 30 , fill = color )
        self.x = self.sx
        self.y = self.sy
        self.cas.move( self.id , randint( 1 , winx ) , randint( 1 , winy ) )
    def move ( self ):
        self.cas.move( self.id , self.x , self.y )
        p = self.cas.coords( self.id )
        if p[0] < 0 :
            self.x = self.sx
        if p[1] < 0 :
            self.y = self.sy
        if p[2] > w :
            self.x = -self.sx
        if p[3] > h :
            self.y = -self.sy
        return p 
class KillBall :
    x = 0 
    y = 0 
    def __init__( self , cas , color , winx , winy ):
        self.cas = cas
        self.id = cas.create_oval( 10 , 10 , 30 , 30 , fill = color )
        self.x = 0 
        self.y = 0 
        self.cas.move( self.id , randint( 20 , winx-20 ) , randint( 20 , winy - 20 ) )
        self.cas.focus_set()
        self.cas.bind( '<Left>' , self.moveleft )
        self.cas.bind( '<Right>' , self.moveright )
        self.cas.bind( '<Up>' , self.moveup )
        self.cas.bind( '<Down>' , self.movedown )
    def killmove( self ):
        self.cas.move( self.id , self.x , self.y )
        self.x = 0 
        self.y = 0 
        p = self.cas.coords( self.id )
        return p 
    def moveleft( self , e ):
        self.x = -10 
    def moveright( self , e ):
        self.x = 10 
    def moveup( self , e ):
        self.y = -10 
    def movedown( self , e ):
        self.y = 10 
tk = Tk() 
w = 500 
h = 200
cas = Canvas( tk , width = w , height = h )
cas.pack()
tk.update()
b1 = Ball( cas , 'red' , w , h )
b2 = Ball( cas , 'green' , w , h )
b3 = Ball( cas , 'yellow' , w , h )
b0 = KillBall( cas , 'Black' , w , h )
flag = True 
num = 0 
while flag :
    p1 = b1.move()
    p2 = b2.move()
    p3 = b3.move()
    p0 = b0.killmove()
    d = ( p1[0] - p0[0] ) ** 2 + ( p1[1] - p0[1] ) ** 2
    if d < 200 :
        num = num + 1 
    d = ( p2[0] - p0[0] ) ** 2 + ( p2[1] - p0[1] ) ** 2
    if d < 200 :
        num = num + 1 
    d = ( p3[0] - p0[0] ) ** 2 + ( p3[1] - p0[1] ) ** 2 
    if d < 200 :
        num = num + 1 
    tk.title( str( num ) )
    tk.update()
    cas.after( 20 )
tk.mainloop()