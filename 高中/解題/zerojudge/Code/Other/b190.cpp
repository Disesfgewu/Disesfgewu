#include <iostream>
using namespace std ;
int move1 = 0 ; // ring 1 : a -> b
void H ( int n , char A , char B , char C )
{
	if ( n == 1 )
	{
		cout << "ring " << n <<  " : " << A << " -> " << C << endl;
	//	move1++ ;
	}
	else
	{
		H( n-1 , A , C , B ) ;
		move1++;
		cout << "ring " << n <<  " : " << A << " -> " << C << endl;
		H( n-1 , B , A , C ) ;
		move1++ ;
	}
}
int main ()
{
	int n ;
	while(cin >> n)
	{
		H( n , 'a' , 'b' , 'c' ) ;
		cout << move1 << endl; 
		move1 = 0 ; 
	}
 } 
