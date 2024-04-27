# 3.7
# Immutablility of Object
a <- list()
tracemem(a)  # show the memory which a is
a$b <- c(1 ,2 ,3)
tracemem(a)

# 3.8 
# Module Pattern

q <- c()
q_size <- 0

enqueue <- function( data ){
  q <<- c( q , data )
  q_size <<- q_size + 1
}
dequeue <- function(){
  first <- q[1]
  q <<- q[-1]
  q_size <<- q_size - 1
  return ( first )
}
size <- function(){
  return ( q_size )
}

enqueue( 1 )
q <- c( q , 5 )
print( size() )
dequeue()
dequeue()
size()

