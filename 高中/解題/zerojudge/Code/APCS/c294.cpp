#include <iostream>
using namespace std;
int main()
{
	int tri[3] = {0} ;
	while ( cin >> tri[0] )
	{
		for ( int i = 1 ; i < 3 ; i++ )
			cin >> tri[i];
		for ( int i = 2 ; i >= 0 ; i-- )
		{
			int y = 0 , m ;
			for ( int j = 0 ; j <= i ; j++ )
			{
				if ( y < tri[j] )
				{
					m = j ;
					y = tri[j];
				}
			}
			int o = tri[i];
			tri[i] = y ;
			tri[m] = o ;
		}
		for ( int i = 0 ; i < 3 ; i++ )
			cout << tri[i] << " ";
		cout << endl;
		if ( tri[0]+tri[1] <= tri[2] )
			cout << "No" << endl;
		else
		{
			int a = tri[0]*tri[0],
				b = tri[1]*tri[1],
				c = tri[2]*tri[2];
			if ( a+b < c )
				cout << "Obtuse" << endl;
			else if ( a+b == c )
				cout << "Right" << endl;
			else if ( a+b > c )
				cout << "Acute" << endl;
		}
	}
	return 0 ;
}
