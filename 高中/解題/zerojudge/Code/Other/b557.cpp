#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int N;
	cin >> N ;
	for ( int o = 0 ; o < N ; o++ )
	{
		int a ;
		cin >> a ;
		int T[a] = {0};
		for ( int q = 0 ; q < a ; q++ )
			cin >> T[q];
	int count = 0 ;
	for ( int i = 0 ; i < N ; i++ )
	{
		float u , t, y ;
		u = T[i];
		T[i] = 0 ;
		for ( int j = 0 ; j < N ; j++ )
		{
			if ( T[j] != 0 )
			{
				y = T[j];
				T[j] = 0 ;
				for ( int z = 0 ; z < N ; z++ )
				{
					if ( T[z] != 0 )
					{
						u = T[z];
						if ( pow(t,2) == pow(y,2)+pow(u,2) )
							count++;	
					}
				}
				T[j] = y ;
			}
		}
		T[i] = u ; 
		}
		cout << count << endl;
	}

	return 0 ; 
 } 
