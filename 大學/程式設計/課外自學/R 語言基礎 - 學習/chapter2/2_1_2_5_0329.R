# 2.1
# Variable 
mean( x <- c( 1 , 2 , 3 ) )
x
# mean( y =  c( 1 , 2 , 3 ) )
# y
# y wouldn't be assigned by '=' , it "may" lose some data
# only '<-' could assign and store some data to a variable in R


# 2.2
# Call functions when assign index
# if we have a function foo()
foo <- function( a , b , c = 1 , d = 2 ){
  return (a+b+c+d)
}
foo( 3 , 4 )
foo( 3 , 4 , 1 )
foo( 3 , 4 , 5 )
foo( a = 3 , b = 4 , d = 100 )

# 2.3 
# Scalar
a <- 3
b <- 4.5
c <- a+b
print(c) # use print() function to print c
c        # not to use print() function to print c 

one <- 80
two <- 90
three <- 75
four <- NA 
# if the data is unkonwn, in R , we can use NA to represent it.
# use is.na() function to check if the data is NA.
is.na(four)

x <- NULL
is.null(x)

is.null(1)
is.null(NA)
is.null(NULL)

is_even <- NULL
if ( is.null(x) ){
  is_even <- TRUE
}else{
  is_even <- FALSE
}
is_even
# NULL : the data is undefined
# NA   : the data is unknown or loss

a <- "hello"
print(a)
a <- 'hello'
print(a)
# in R , "" and '' both are the string type

TRUE & TRUE  # & and
TRUE | FALSE # | or
!TRUE        # ! not

sex <- factor( "m" , c( "m" , "f" ) )
sex
nlevels(sex)
levels(sex)

levels(sex) <- c( "m" , "qwqw" ) 
sex

ordered( "a" , c( "a" , "b" , "c" ) )
ordered( 4 , c( 4 , 2 , 3 ))

# 2.4
# Vector
x <- c( "a" , "b" , "c" )
x[1]
x[3]

x[-1]  # call elements in x except index = 1 
x[-3]  # call elements in x except index = 3

x[c(1,2)] # call elements x[1] and x[2]
x[c(1,3)] # call elements x[1] and x[3]

x[c(1:2)] # call elements x[1~2]
x[c(1:3)] # call elements x[1~3]

x <- c( 1 , 3 , 4 )
names(x) <- c( "a" , "b" , "c" )
x
x["a"]
x[c("b","c")]
names(x)[2]

length(x)
nrow(x) # Only use in Matrix
NROW(x) # Can use in Matrix or Vector

x <- c(1,2,3)
y <- c(2,3,4)
t <- c(1,2,3)
k <- c(1000,1123,123)
z <- c(1234,1231,12345)
identical(x,y,t)
identical(x,t)
identical(x,y,z)
# identical() : to identify if the vectors are the same

1 %in% x
1000 %in% k
-12 %in% y
# a %in% v : to identify if element a is in the vector v
x
x + 1
x
x - 1
x <- x+1
x 
x <- x-1

c(1,2,3) == c(1,2,4)
c(1,2,3) != c(1,2,13)

union( x , y )     # x or y 
intersect( x , y ) # x and y
setdiff( x, y )    # x - y

setequal(c("a","b","c") , c("a","b"))
setequal(c("a","b","c") , c("a","b","c","c"))

x <- seq( 1 , 5 )
x
x <- seq( 5 , 1 )
x

x <- 1:5
x
x <- 5:1
x

rep( 1:2 , times = 5 )
rep( 1:2 , each = 5 )
rep( 1:2 , each = 2 , times = 5 )
rep( 1:2 , times = 2 , each = 5 )
# each is first -> times is second

# 2.5 
# List
x <- list( name="foo" , height = 70)
x

x$name
