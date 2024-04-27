# 2.9
# Type detect

# class() return the type of variable

class( c(1,2) )
class( matrix( c(1,2) ) )
class( data.frame( x=c(1,2) , t = c(3,4) ) )

# str() return the inner structure of variables

str( c(1,2) )
str( matrix( c(1,2)))
str( list( c(1,2)))
str( data.frame( x=c(1,2) ) ) 

# 2.10
# switch the type

x <- c( "a" , "b" , "c" )
class( x )
x
x <- as.factor(x)
class( x )
x
x <- as.character(x)
x

x <- matrix( c(1:9) , ncol = 3 , byrow = T )
class(x)
x
x <- as.data.frame(x)
class(x)
x
x <- data.frame( x <- as.matrix(x) )
class(x)
x
