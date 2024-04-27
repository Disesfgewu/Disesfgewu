#include <iostream>
#include <string>
using namespace std;
int main ()
{
	int N;
	while ( cin >> N )
	{
		char sl[N];
		int sll[N] = {0};
		for ( int i = 0 ; i < N ; i++ )
		{
			string s ;
			cin >> s ;
			int y = s.length();
			for ( int j = 0 ; j < N ; j++ )
			{
				if ( y > sll[j] )
				{
					sll[j] = y ;
					
				}
			}
		}
	}
}
