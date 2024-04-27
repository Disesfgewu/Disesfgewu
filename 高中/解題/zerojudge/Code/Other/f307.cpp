#include <iostream>
#include <algorithm>
using namespace std;
char nm[202][202];
int T , n , m ;
int a ( int i , int j )
{
	//cout << int( nm[i][j] ) << endl;
	int count[4] = {0};
	if ( int(nm[i+1][j]) == 46 )
	{	//	cout << count[0] << endl;
		count[0] += a( i+1 , j );

	}if ( int(nm[i-1][j]) == 46 )
	{//	cout << count[1] << endl;
		count[1] += a( i-1 , j );
	
	}if ( int(nm[i][j+1]) == 46 )
	{//cout << count[2] << endl;
		count[2] += a( i , j+1 );
		
	}if ( int(nm[i][j-1]) == 46  )
	{	//cout << count[3] << endl;
		count[3] += a( i , j-1 );
	
	}sort( count , count + 4 );
	return count[0] ;	
}
int main ()
{
	while ( cin >> T )
	{
		for ( int i = 0 ; i < T ; i++ )
		{
			//nm[202][202] = {0};
			cin >> n >> m ;
			int q , w ;
			for ( int j = 1 ; j <= n ; j++ )
			{
				string s;
				cin >> s ;
				for ( int z = 0 ; s[z] != '\0' ; z++ )
				{
					nm[j][z+1] = s[z] ;
					if ( int( nm[j][z+1] ) == 89 )
					{
						q = j ;
						w = z+1 ;
						cout << q << " " << w << endl;
					}
				//	cout << int( nm[i][j] ) << endl; 
				}
			}
			int count = a( q , w );
			if ( count == 0 )
			 	cout << "Impossible!" << endl;
			else
				cout << count << endl;
		}
	}
	return 0 ;
 } 
