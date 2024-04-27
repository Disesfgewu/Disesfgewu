# 3.1
# the special od R
# ...

# 3.1 
# The control of flow

# If

if ( T )
{
  print( "TRUE" )
  print( "hello" )
} else
{
  print( "False" )
}

x <- c( 1 : 5 )
y <- ifelse( x %% 2 == 0 , "even" , "odd" )
y
class(y)

# for-loop

for ( i in 1:10 )
{
  print( i )
}

# while-loop

i <- 1
while ( i <= 10 )
{
  print( i )
  i <- i+1
}

# repeat-loop

i <- 1
repeat
{
  print( i )
  if ( i == 10 ) break
  i <- i+1
}

# 3.3
# calculate

x <- 1:5 *2 + 1
class( x )
x

# vector calculate

x <- c( 1:5 )
x + 1

sum( x )    # sum
median( x ) # median number
mean( x )   # mean value

d <- data.frame( x = c( 1 : 5 ) , y = c( "a" , "b" , "c" , "d" , "e" ) )
d[c( T , F , T , T , F ) , ]

d[d$x %% 2 == 0 , ]


