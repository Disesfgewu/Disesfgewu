#include <stdio.h>
int main ()
{
	int coffee_price_1 , 
		coffee_price_2 ,
		juice_price_1 , 
		juice_price_2 ,
		num1 , num2 ,
		coffee_num , 
		juice_num ,
		totalPrice ;
	printf( "Give four prices of coffee and juice: " ) ;
	scanf( "%d %d %d %d" , &coffee_price_1 , &coffee_price_2 , &juice_price_1 , &juice_price_2 ) ;
	printf( "How many coffee and juice do you want?: " ) ;
	scanf( "%d %d" , &num1 , &num2 ) ;
	if ( coffee_price_1 > coffee_price_2 )
		coffee_num = coffee_price_1 ;
	else
		coffee_num = coffee_price_2 ;
	if ( juice_price_1 > juice_price_2 )
		juice_num  = juice_price_1 ;
	else 
		juice_num  = juice_price_2 ;
	totalPrice = coffee_num * num1 + juice_num * num2 ;
	printf( "totalPrice = %d\n" , totalPrice ) ;
} 
