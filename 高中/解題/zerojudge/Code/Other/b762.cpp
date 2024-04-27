#include <iostream>
#include <cstring>
using namespace std ;
void f ( int n )
{
	if ( n < 3 )
		cout << "You have slain an enemie.\n" ;
	else if ( n == 3 )
		cout << "KILLING SPREE!\n" ;
	else if ( n == 4 )
		cout << "RAMPAGE~\n" ;
	else if ( n == 5 )
		cout << "UNSTOPPABLE!\n" ;
	else if ( n == 6 )
		cout << "DOMINATING!\n" ;
	else if ( n == 7 )
		cout << "GUALIKE!\n" ;
	else if ( n >= 8 )
		cout << "LEGENDARY!\n" ;
}
int main()
{
	int n , count = 0 , countk = 0 , countd = 0 , counts = 0 ;
	string s ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> s;
		//cout << i << "\t" ;
		if ( s == "Get_Kill" )
		{
			count++ ;
			f( count ) ;
			countk++ ;
		}
		else if ( s == "Get_Assist" )
		{
			counts++ ;
		}
		else if ( s == "Die" )
		{
			countd++ ;
			if ( count < 3 )
				cout << "You have been slained.\n" ;
			else
				cout << "SHUTDOWN.\n" ;
			count = 0 ;
		}
	}
	printf( "%d/%d/%d\n" , countk , countd , counts ) ;
 } 
