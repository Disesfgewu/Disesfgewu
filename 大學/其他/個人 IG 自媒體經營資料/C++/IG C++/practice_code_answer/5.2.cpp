#include <iostream>
using namespace std ;

int main () {
	int i = 0 ;
	while ( i < 5 ) 
	{
		int j = 0 ;
		while ( j < 5-i-1 ) 
		{
			cout << " " ;
			j++ ;
		}
		j = 0 ;
		while ( j <= i ) 
		{
			cout << "*" ;
			j++ ;
		}
		cout << endl ;
		i++ ; 
	} 
	return 0 ;
}
