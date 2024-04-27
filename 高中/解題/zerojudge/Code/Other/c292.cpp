#include <iostream>
using namespace std;
int main()
{
	int n , m ;
	while ( cin >> n )
	{
		cin >> m ; 
		int s[n][n] ={0};
		for ( int i = 0 ; i < n ; i++ )
			for ( int j = 0 ; j < n ; j++ )
				cin >> s[i][j];
		int a = n/2 , b = n/2 , count = 1 ;
		cout << s[a][b];
		switch (m)
		{
			case 1 :
				for ( int i = 1 ; ; i += 2 )
				{
					if ( count == n*n )
						break;
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						a -= 1;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						b += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						a += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						a -= 1 ;
						cout << s[a][b] ;
						count++;
					}
				}
				cout << endl;
				break;
			case 0 :
				for ( int i = 1 ; ; i += 2 )
				{
					if ( count == n*n )
						break;
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						b -= 1 ;
						cout << s[a][b] ;
						count++;
						
					}
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						a -= 1 ;
						cout << s[a][b] ;
						count++;
						
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						b += 1 ;
						cout << s[a][b] ;
						count++;
						
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						a += 1 ;
						cout << s[a][b] ;
						count++;
					} 
				}
				cout << endl;
				break;
			case 2 :
				for ( int i = 1 ; ; i += 2 )
				{
					if ( count == n*n )
						break;
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						b += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						a += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						b -= 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						a -= 1 ;
						cout << s[a][b] ;
						count++;
					}
				}
				cout << endl;
				break;
			case 3 :
				for ( int i = 1 ; ; i += 2 )
				{
					if ( count == n*n )
						break;
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						a += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i ; j++ )
					{
						if ( count == n*n )
							break;
						b -= 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						a += 1 ;
						cout << s[a][b] ;
						count++;
					}
					for ( int j = 1 ; j <= i+1 ; j++ )
					{
						if ( count == n*n )
							break;
						b += 1 ;
						cout << s[a][b] ;
						count++;
					}
				}
				cout << endl;
				break;
			default :
				break;
		}
	}
	return 0 ;
}
