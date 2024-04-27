#include <iostream>
using namespace std;
int main ()
{
	int a , b , c ;
	int A[5] = {0} , B[5] = {0} ;
	cin >> a >> b >> c ;
	for ( int i = 0 ; i < 5 ; i++ )
		cin >> A[i];
	for ( int i = 0 ; i < 5 ; i++ )
		cin >> B[i];
	int count = 0 , m = 2 ;
	int i ;
	for ( i = 0 ; i < 5 ; i++ )
	{
		if ( A[i] == a || A[i] == b ) 
			count += B[i];		
	}
	for ( i = 0 ; i < 5 ; i++ )
	{
		if ( A[i] == c )
		{
			count -= B[i];
			m = 1 ;
		}
	}
	if ( count < 0 )
		cout << "0" << endl;
	else
		cout << count*m << endl;
 } 
