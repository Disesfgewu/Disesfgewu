#include <stdio.h>

int main ()
{
	float height ;
	float weight ;
	char space ;
	printf( "Please input the height and weight : " ) ;
	while ( scanf( "%f%f"  , &height  , &weight )  ) 
	{
		float BMI = ( weight ) / ( height*height ) ;
		printf( "The BMI will become %f\n" , BMI ) ;
		printf( "Please input the height and weight : " ) ;
		weight = 0 ;
		height = 0 ;
	}
	return 0 ;
}


