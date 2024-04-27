#include <stdio.h>
#include <math.h>
int main ()
{
	float height , weight , bmi ;
	printf( "Input height(cm): " ) ;
	scanf( "%f" , &height ) ;
	printf( "Input weight(kg): " ) ;
	scanf( "%f" , &weight ) ;
	bmi = weight / pow( height/100 , 2 ) ;
	printf( "Your BMI is %.1f\n" , bmi ) ;
	if ( bmi < 18.5 )
	{
		printf( "You are Underweight\n" ) ;
	}
	else if ( bmi < 25 )
	{
		printf( "You are Normal\n" ) ;
	}
	else if ( bmi < 30 )
	{
		printf( "You are Overweight\n" ) ;
	 } 
	 else 
	 {
	 	printf( "You are Obesity\n" ) ;
	 }
	 return 0 ;
}
