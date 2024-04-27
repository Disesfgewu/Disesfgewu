#include <iostream>
using namespace std;
int a[10][10] , b[10][10];
int r , m , c ;
void sw ( int o )
{
	if ( o % 2 == 0 )
		for ( int j = 0 ; j < r ; j++ )
			for ( int z = 0 ; z < c ; z++ )
				b[z][j] = a[j][c-z-1];
	else
		for ( int j = 0 ; j < c; j++ )
			for ( int z = 0 ; z < r ; z++ )
				a[z][j] = b[j][r-z-1]; 
}
void ud( int o )
{
	if ( o % 2 == 0 )
		for ( int j = 0 ; j < r/2 ; j++ )
		{
			for ( int z = 0 ; z < c ; z++ )
			{
				int k = a[j][z];
				a[j][z] = a[r-1-j][z];
				a[r-1-j][z] = k ;
			}
		}
	else
		for ( int j = 0 ; j < c/2 ; j++ )
			for ( int z = 0 ; z < r ; z++ )
			{
				int k = b[j][z];
				b[j][z] = b[r-1-j][z];
				b[r-1-j][z] = k ;
			}
}
int main ()
{
	while ( cin >> r >> c >> m )
	{
		for ( int i = 0 ; i < r ; i++ )
			for ( int j = 0 ; j < c ; j++ )
				cin >> b[i][j];
		int o = 0 , c[m] = {0};
		for ( int i = 0 ; i < m ; i++ )
			cin >> c[i];
		for ( int i = m-1 ; i >= 0 ; i-- )
		{
			if ( c[i] == 0 )
			{
				sw(o);
				o++;	
			}
			else
			{
				ud(o);
			}
		}
		if ( o % 2 == 0 )
		{
			cout << r << " " << c << endl;
			for ( int i = 0 ; i < r ; i++ )
			{
				for ( int j = 0 ; int(j) < c ; j++ )
					cout << a[i][j] ;
				cout << endl;
			}
		}
		else
		{
			cout << c << " " << r << endl;
			for ( int i = 0 ; i < c ; i++ )
			{
				for ( int j = 0 ; j < r ; j++ )
					cout << b[i][j];
				cout << endl;
			} 
		}
	}
	return 0 ;
 } 
