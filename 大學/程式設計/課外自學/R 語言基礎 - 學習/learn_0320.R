x <- 5
class(x)
x <- "dog"
class(x)
x <- ( 5 > 4 )
class(x)

x <- c( 1 , 2 , 3 , 4 )
x
x <- c( 1 : 10 )

y <- c( 2 : 11 )

x^y  # could use vector to calculate

x[1] # index start from 1

x <- c( "Graduate" , "College" , "High" )
x <- c( x , "High" , "Other")
x

x1 <- as.factor(x)
x1
class(x1)
as.numeric(x1)
x1 <- as.numeric( x1 )
class( x1 )
x1[2]
?list
y = as.list( 10 , 11 , 12 )

Matrix = matrix( 1:3 , ncol = 3 , nrow = 1 , byrow = TRUE , dimnames = y )
Matrix
?matrix
