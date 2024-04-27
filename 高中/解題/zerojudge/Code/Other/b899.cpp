#include <iostream>
#include <cmath>
using namespace std;
float N[3][2] = {0} ;

int line ( void )
{
	float a = sqrt(pow((N[0][0]-N[1][0]), 2 ) + pow((N[0][1]-N[1][1]) , 2 )),
					b = sqrt(pow((N[1][0]-N[2][0]), 2 ) + pow((N[1][1]-N[2][1]) , 2 )),
					c = sqrt(pow((N[0][0]-N[2][0]), 2 ) + pow((N[0][1]-N[2][1]) , 2 ));
	//cout << a <<" "<< b << " "<<c << '\n'; 
	//int A = 0 , B = 1 , C = 2;
	if ( a == b )
		return 1;
	else if ( a == c )
		return 0;
	else if ( b == c )
		return 2 ;
}
int Y ( void )
{
	if ( N[2][1] == N[0][1] )
		return N[1][1];
	else if ( N[2][1] == N[1][1] )
		return N[0][1];
	else 
		return -2 ;
}
int X ( void )
{
	if ( N[2][0] == N[0][0] )
	{
		int y = Y();
		if ( y >= 0 )
			cout << N[1][0] << " " << Y() << endl;
	}
	else if ( N[2][0] == N[1][0] )
	{
		int y = Y();
		if ( y >= 0  )
			cout << N[0][0] << " " << Y() << endl;
	}
	else
		return -1;
	return Y();
}
int main ()
{
	while ( cin >> N[0][0] >> N[0][1] )
	{
		for ( int i = 1 ; i < 3 ; i++ )
		{
			for ( int j = 0 ; j < 2 ; j++ )
				cin >> N[i][j];
		}
		int h = line();
		for ( int i = 0 ; i < 2 ; i++ )
		{
			int q = N[h][i] ;
			N[h][i] = N[2][i];
			N[2][i] = q ;
		}
		int P = X();
		if ( P == -1 )
		{
			int count = 0 ;
			for ( int i = 0 ; i < 2 ; i++ )
				count += N[i][1] ; 
			cout << N[2][0] << " " << count << endl;
		}
		else if ( P == -2 )
		{
			int count = 0 ;
			for ( int i = 0 ; i < 2 ; i++ )
				count += N[i][0] ; 
			cout << count << " " << N[2][1] << endl;
		}
	}
	return 0 ;
 } 
