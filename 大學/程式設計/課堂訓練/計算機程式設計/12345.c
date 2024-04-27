#include <stdio.h>
//#include <math.h>
int main ()
{
	while ( 1 )
	{
		float height , weight , BMI \[];
		printf( "請輸入身高(cm)和體重(pound): " ) ;
		scanf( "%f" , &height ) ;
		if ( height == -1 )
		{
			break ;
		}
		scanf( "%f" , &weight ) ;
		height = height / 100 ;
		weight = weight * 0.454 ;
		BMI = weight/( height*height ) ;
		if ( 0.5 > height || height > 2.5 )
			printf( "Input Height Error\n" ) ;
		else if ( BMI > 24.00 )
			printf( "BMI too high" ) ;
		else if ( BMI < 18.5 )
			printf( "BMI too low" ) ;
		else 
			printf( "%.2f" , BMI ) ;
		printf( "\n" ) ;
	}
 } 
