#include <stdio.h>
#include <math.h>
int main ()
{
	float size_of_virus ;
	printf( "Input the diameter of the virus: " ) ;
	scanf ( "%f" , &size_of_virus ) ;
	size_of_virus *= pow( 10 , -9 ) ;
	printf( "The diameter of the virus in exponential format: %.4e\n" , size_of_virus ) ;
}
