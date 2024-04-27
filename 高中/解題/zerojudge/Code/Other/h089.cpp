#include <iostream>
using namespace std ;
void h( int i , char a , char b , char c )
{
	if ( i == 1 )
		cout << "from "<< a << " to "<< c << "\n" ;
	else
	{
		h( i-1 , a , c , b );
		cout << "from "<< a << " to "<< c << "\n" ;
		h( i-1 , b , a , c );
	 } 
}
int main ()
{
	int n ;
	cin >> n ;
	h( n ,'A' , 'B' , 'C') ;
 } 
