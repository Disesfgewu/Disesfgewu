#include <iostream>
using namespace std ;
void H ( int n , char A , char B , char C )
{
	if ( n == 1 )
	{
		cout << "Move ring " << n <<  " from " << A << " to " << C << endl;

	}
	else
	{
		H( n-1 , A , C , B ) ;
		cout << "Move ring " << n <<  " from " << A << " to " << C << endl;
		H( n-1 , B , A , C ) ;
	}
}
int main ()
{
	int n ;
	while(cin >> n)
	H( n , 'A' , 'B' , 'C' ) ;
 } 
