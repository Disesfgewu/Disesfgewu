#include <iostream>
#include <queue>
using namespace std ;
queue <int> qu ;
int n , k , m ;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n ;
	while ( n-- )
	{
		cin >> k ;
		if ( k == 1 )
		{
			cin >> m ;
			qu.push( m ) ;
		}
		else if ( k == 2 )
		{
			if ( qu.empty() )
			{
				cout << "-1" << endl ;
			}
			else
			{
				cout << qu.front() << endl ;
			}
		}
		else
		{
			if ( qu.empty() )
				continue ;
			else
				qu.pop() ;
		}
	}
	return 0 ;
 } 
