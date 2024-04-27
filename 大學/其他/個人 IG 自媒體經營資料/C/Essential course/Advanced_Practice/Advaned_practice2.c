#include <stdio.h>

int main ()
{
	float height ;
	float weight ;
	printf( "Please input the height : " ) ;
	scanf( "%f" , &height ) ;
	printf( "Please input the weight : " ) ;
	scanf( "%f" , &weight ) ;
	float BMI = ( weight ) / ( height*height ) ;
	printf( "The BMI will become %f\n" , BMI ) ;
	return 0 ;
}


