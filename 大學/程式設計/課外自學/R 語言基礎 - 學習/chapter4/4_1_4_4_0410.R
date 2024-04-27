# 4.1
# Iris data
x <- head( iris )
x
class( x )
x[2]
str( iris )
iris3
help( iris3 )

data( mtcars )
head( mtcars)

# 4.2 
# R/W file
x <- read.csv("4_2_test.csv")
x
str(x)
names(x) <- c( "Id" , "Name" , "Score")
x