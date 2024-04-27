#include <stdio.h>
int main()
{	
	char s[100000] , c[100000] ;
	int a , b ;
	while ( scanf( "%s" , s ) )
	{
		stack<long long> k ; 
		stringstream ss( s ) ;
		while ( ss >> c ) 
		{
			if ( c == "+" )
			{ 
				a = k.top() ;
				k.pop() ; 
				b = k.top() ;
				k.pop() ;
				k.push ( a + b );
			}
			else if ( c == "-" )
			{ 
				a = k.top() ;
				k.pop() ;
				b = k.top() ;
				k.pop() ;
				k.push ( b - a ) ;
			}
			else if ( c == "*" )
			{
				a = k.top() ;
				k.pop();
				b = k.top() ;
				k.pop() ;
				k.push( a * b ) ;
			}
			else if ( c == "/" )
			{
				a = k.top() ;
				k.pop() ;
				b = k.top() ; 
				k.pop() ;
				k.push ( b / a ) ;
			}
			else
				k.push ( stoi( c ) ) ;
		}
		cout << k.top() << "\n" ;
	}
	return 0 ;
}
