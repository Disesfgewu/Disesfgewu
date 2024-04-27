#include <stdio.h>
#include <math.h>
int main ()
{
	while ( 1 )
	{
		int h , w;
		printf( "請輸入身高(cm)和體重(pound): " );
		scanf ( "%d" , &h );
		if ( h == -1 )
			break ;
		if ( h > 250 || h < 50 ) 
		{	
			printf( "Input Height Error\n" );
			continue;
		}
		scanf ( "%d" , &w );
		if ( w == -1 )
			break;
		if ( w > 300 || w < 20 ) 
		{	
			printf( "Input Weight error\n" );
			continue;
		}
		float BMI = ( ( float )w*0.454 )/pow( (float)h / 100  , 2 );
		int BMI2 = BMI*100;
		float BMI3 = (float)BMI2;
		if ( BMI >= 18.50 && BMI <= 24.00 )
			printf( "%.2f\n" ,  BMI3/100 );
		else 
		{
			if ( BMI > 24.00 )
				printf( "BMI too high\n");
			else
				printf( "BMI too low\n" ); 
		}
	}
	return 0 ;
}
