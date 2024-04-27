# 3.4 
# Define function
f <- function( x, y ){
  print(x)
  print(y)
}
f( 1, 2)
f( 3, 1000)
f( y=100123 , x = -1321)

f <- function( ... ){
  arge = list( ... )
  for ( i in arge ){
    print( i )
  }
}
f( 1, 2,3,4,4,5)
f( 'a' , "as" , 'fr')

f <- function( z , ... ){
  print(z)
  arge = list( ... )
  for ( i in arge ){
    print(i)
  }
}
f( 1, 2,3,4,4,5)

f <- function( x ){
  if ( x <= 1 ){
    return (1) 
  }
  return (f(x-1) + f(x-2))
}
f(5)

f <- function( x1 ){
  return ( function( x2 ) {
    return ( x1+x2 )
  })
}
g <- f(1)
g(2)

# 3.5
# Scope
n <- 1
f <- function(){
  print(n)
}
f()
n <- 100
f()

n <- 1
f <- function(){
  n <- 200
  print(n)
}
f()
n <- 100
f()

rm( list = ls() )
# delete all the memory of the variables

f <- function(){
  a <- 1
  g <- function(){
    a <- 2
    print(a)
  }
  g()
  print(a)
}
f()

f <- function(){
  a <- 1
  g <- function(){
    a <<- 2
    print(a)
  }
  g()
  print(a)
}
f()

# 3.6
# Call by Value and Call by Reference

f <- function( df ){
  df$a <- c( 1, 2, 3)
}
dfing <- data.frame( a = c( 4,5,6 ) )
f( dfing )
dfing


f <- function( df ){
  df$a <- c( 1, 2, 3)
  return (df)
}
dfing <- data.frame( a = c( 4,5,6 ) )
dfing <- f( dfing )
dfing
