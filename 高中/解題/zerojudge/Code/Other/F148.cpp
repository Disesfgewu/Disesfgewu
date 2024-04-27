#include <iostream>
using namespace std;
int main ()
{
	int a , b , c ;
	while ( cin >> a >> b )
	{
		cin >> c ;
		char s[a][b];
		int count1 = 0;
		for ( int i = 0 ; i < a ; i++ )
		{
			for ( int j = 0 ; j < b ; j++ )
			{
				cin >> s[i][j];
				if ( int(s[i][j] >= 97 ))
						count1++;
			}
		}
		if ( count1 < c )
		{
			cout << "Mission fail." << endl;
		}
		else
		{
			int e = 0 ;
			int count2 = 97 ;
			while ( e < c )
			{
				for ( int i = 0 ; i < a ; i++ )
				{
					for ( int j = 0 ; j < b ; j++ )
					{
						if ( int(s[i][j]) == count2 )
						{
							e++;
							cout << i << " " << j << endl; 
						}
					}
				}
				count2++;
			}
		}
	}
	return 0 ;
 } 
