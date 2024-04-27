#include <iostream>
using namespace std;

int main ()
{
	int number;
	while ( cin >> number )
	{
		int abc[number][3] = {0} ;
		for ( int i = 0 ; i < number ; i++ )
		{
			for ( int j = 0 ; j < 3 ; j++ )
			{
				cin >> abc[i][j];
			}
		}
		for ( int i = 0 ; i < number ; i++ )
		{
			for ( int j = 0 ; j < 3 ; j++ )
			{
				int c = abc[i][j];
				abc[i][j] = 0 ;
				int count = 0 ;
				for ( int z = 0 ; z < 3 ; z++ )
				{
					count = count + abc[i][z]*abc[i][z];
				}
				if ( c*c == count )
				{
					cout << c << endl;
					break;
				} 
				else 
				{
				 	abc[i][j] = c ;
				}
					
			}
		}	
	}
	return 0 ;
 } 
