#include <iostream>

using namespace std;
int a , b , h[10001] = {0} ;
int j ( int p )
{
	if ( h[p] == 1 )
		return 1 ;
	else
	{
		int c = 0 ;
		for ( int i = 1 ; i <= p ; i++ )
		{
			if ( p % i == 0 )
				c++;
		}
		if ( c == 2 )
		{
			h[p] = 1 ;
			return 1 ;
		}
		else
			return 0 ;
	}
}
int main ()
{
	while ( cin >> a >> b )
	{
		int count = 0 , g = 0 ;
		for ( int i = a ; i <= b ; i++ )
		{
			int u = j(i);
			if ( u == 1 )
			{
				g++;
				count += i ;
			}
		}
		cout << g << endl;
		cout << count << endl;
	}
	return 0 ;
 } 
