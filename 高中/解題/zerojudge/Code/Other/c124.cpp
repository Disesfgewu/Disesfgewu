#include <iostream>
#include <stack>
using namespace std ;
stack <int> s ;
int n ;
bool ch ( int a[] , int b[] )
{
	int i = 0 , j = 0 ;
	while ( i < n )
	{
		cout << "hjk" << endl ;
		if ( b[j] == s.top() && !s.empty() )
		{
			cout << s.top() << endl ;
			s.pop() ;
			j++ ;
		}
		else
		{
			s.push( a[i] ) ;
			i++ ;
		}
	}
	if ( j == n-1 )
		return true ;
	else
		return false ;
}
void clear ( void )
{
	while ( !s.empty() )
		s.pop() ;
}
int main ()
{
//	int n ;
	cin >> n ;
	int a[n] = {0} , b[n] = {0} ;
	stack <int> s ;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> a[i] ;
	}
	while ( cin >> b[0] )
	{
		clear();
		int c[n] = {0} ;
		if ( b[0] == 0 )
			break ;
		for ( int i = 1 ; i < n ; i++ )
			cin >> b[i] ;
		if ( ch ( a , b ) )
			cout << "yes\n" ;
		else
			cout << "no\n" ;
	}
}
