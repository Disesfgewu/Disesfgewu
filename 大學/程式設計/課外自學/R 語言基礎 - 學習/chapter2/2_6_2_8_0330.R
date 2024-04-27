# 2.6
# Matrix
x <- matrix( c(1:9) , nrow = 3)
x
x <- matrix( c(1:9) , ncol = 3 )
x
x <- matrix( c(1:9) , ncol = 3 , byrow = T )
x
x <- matrix( c(1:9) , ncol = 3 , byrow = T , dimnames = list( c("r1","r2","r3") , c("c1","c2","c3") ) )
x
x[1,2]
x[3,3]

# Matrix multiply

x %*% x 

x <- matrix( c(1:4) , nrow = 2 )
# use solve() function to get the inverse matrix
solve(x)
x %*% solve(x)

# 2.7
# Array
x <- array( 1:12 , dim=c(3,4)) # declare a 3*4 array
x
x <- array( 1:12 , dim=c(2,3,2)) # declare a 2*3*2 array
x

# 2.8 
# Dataframe
d <- data.frame(x=c(1:4), y=c(5:8))
d
str(d)

d$x
d$x <- 11:14
d$x

d$addition <- c( 8:11 )
str(d)
d
View(d)
d[, names(d) %in% "addition" ]
d[, names(d) %in% "addition" , drop=F]
d[, !names(d) %in% "addition" , drop=F ]

d <- data.frame( x = c(1:1000) )
d

head(d) # print first -> sixed data
tail(d) # print the least one -> the least sixed data

View(d) # View the data frame
