#include <iostream>
#include <cmath>
#include <vector> 
using namespace std;
long long a1 , b1 , a2 , b2 ;
long long as = 100000007 ;
int main ()
{
	cin.tie(0) ;
	cin >> a1 >> b1 ;
	vector <long long > a[512] , b[512] , c[512] ;
	for ( int i = 0 ; i  < 512 ; i++ )
		a[i].resize( 0 ) , b[i].resize(0) , c[i].resize(0) ;
	// , A[b1][a1] = {0} ;
	long long h ;
	for ( int i = 0 ; i < a1 ; i++ )
		for ( int j = 0 ; j < b1 ; j++ )
		{
			cin >> h ;
			a[i].push_back( ( h % as + as ) % as );
			//A[i][j] = b[i][j] ;
		}
	cin >> a2 >> b2 ;
	//long long b[a2][b2] = {0} ;//, long B[b2][a2] = {0} ;
	for ( int i = 0 ; i < a2 ; i++ )
		for ( int j = 0 ; j < b2 ; j++ )
		{
			cin >> h ;
			b[i].push_back( ( h % as + as ) % as ) ;			
		//	B[i][j] = b[i][j] ;
		}
	if ( a2 != b1 )
	{
		if ( b2!= a1 )
			cout << "unmultipliable!" << '\n' ;
		else
			cout << "incommutable!" << '\n' ;
	}
	else
	{
		long long z ;
		for ( int i = 0 ; i < a1 ; i++ )
		{
			for ( int j = 0 ; j < b2 ; j++ )
			{
				for ( int k = 0 ; k < b1 ; k++ )
				{
					c[i].push_back( ( ( a[i][k]*b[k][j] ) % as + as ) % as ); //+= (  ;
				}	
			}
		}
		for ( int i = 0 ; i < a1 ; i++ )
		{
			for ( int j = 0 ; j < b2 ; j++ )
				cout << c[i][j] << " " ;
			cout <<'\n';	
		}
	}
 } 
