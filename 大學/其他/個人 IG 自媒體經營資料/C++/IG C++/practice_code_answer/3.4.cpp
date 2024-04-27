#include <iostream>
using namespace std ;

int main ()
{
	float height ;
	float weight ;
	char space ;
	cout << "Please input the height and weight : " ;
	while ( cin >> height >> weight ) 
	{
		float BMI = ( weight ) / ( height*height ) ;
		cout << "The BMI will become " << BMI << endl ;
		cout << "Please input the height and weight : " ;
		weight = 0 ;
		height = 0 ;
	}
	return 0 ;
}
