#include <iostream>
using namespace std ;

int main ()
{
	float height ;
	float weight ;
	cout << "Please input the height : " ;
	cin >> height ;
	cout << "Please input the weight : " ;
	cin >> weight ;
	float BMI = ( weight ) / ( height*height ) ;
	cout << "The BMI will become " << BMI << endl ;
	return 0 ;
}


