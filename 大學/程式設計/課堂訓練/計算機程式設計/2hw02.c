#include <stdio.h>
#include <math.h>
int main ()
{
	//Simple BMI Calculator
	float height , weight , BMI ;
	printf( "Please enter your height " ) ;
	scanf ( "%f" , &height ) ;
	printf( "Please enter your weight " ) ;
	scanf ( "%f" , &weight ) ;
	printf( "BMI = %.1f " , weight/pow( height , 2 ) ) ; 
}
