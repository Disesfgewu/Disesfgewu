#include <iostream>
using namespace std ;
int main ()
{
	int n , R ;
	while ( cin >> n >> R )
	{
		int all_people[n] ;
		for ( int i = 0 ; i < n ; i++ )
		{
			all_people[i] = 0 ;
		} // µ¥¦P©ó int all_people[n] = {0} ;
		for ( int i = 0 ; i < R ; i++ )
		{
			int people ;
			cin >> people ;
			all_people[ people - 1 ] = 1 ;
		}
		int count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			if ( all_people[i] == 0 )
			{
				cout << i+1 << " " ;
				count = 1 ;
			}
		}
		if ( count == 0 )
			cout << "*" ;
		cout << endl ; 
 	} 
}
