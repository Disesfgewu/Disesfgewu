#include <iostream>
using namespace std;
int main ()
{
	int r , c , m , cube1[10][10] , cube2[10][10];
	while ( cin >> r >> c >> m )
	{
		//int cube1[r][c] = {0};
		//int cube2[c][r] = {0};
		int o = 0 ;
		for ( int i = 0 ; i < r ; i++ )
			for ( int j = 0 ; j < c ; j++ )
				cin >> cube1[i][j];
		int s[m] = {0};
		for ( int i = 0 ; i < m ; i++ )
			cin >> s[i];
		for ( int i = m-1 ; i >= 0 ; i-- )
		{
			if ( s[i] == 0 )
			{
				if ( o % 2 == 0 )
				{	for ( int j = 0 ; j < r ; j++ )
						for ( int z = 0 ; z < c ; z++ )
							cube2[z][j] = cube1[j][c-z-1];
				} 
				else
					for ( int j = 0 ; j < c; j++ )
						for ( int z = 0 ; z < r ; z++ )
							cube1[z][j] = cube2[j][r-z-1];
				o++;
			}
			else
			{
				if ( o % 2 == 0 )
					for ( int j = 0 ; j < r/2 ; j++ )
					{
						for ( int z = 0 ; z < c ; z++ )
						{
							int a = cube1[j][z];
							cube1[j][z] = cube1[r-1-j][z];
							cube1[r-1-j][z] = a ;
						}
					}
				else
					for ( int j = 0 ; j < c/2 ; j++ )
						for ( int z = 0 ; z < r ; z++ )
						{
							int a = cube2[j][z];
							cube2[j][z] = cube2[r-1-j][z];
							cube2[r-1-j][z] = a ;
						}
			}
		}
		if ( o %2 == 0 )
		{
			cout << r << " " << c << endl;
			for ( int i = 0 ; i < r ; i++ )
			{
				for ( int j = 0 ; j < c ; j++ )
					cout << cube1[i][j] << " ";
				cout << endl;
			}
		}
		else
		{
			cout << c << " " << r << endl;
			for ( int i = 0 ; i < c ; i++ )
			{
				for ( int j = 0 ; j < r ; j++ )
					cout << cube2[i][j] << " ";
				cout << endl;
			}
		}
	}
	return 0 ;
 }
