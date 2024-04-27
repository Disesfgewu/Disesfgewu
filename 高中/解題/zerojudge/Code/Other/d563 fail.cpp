#include <iostream>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int A[n] = {0};
		for ( int i = 0 ; i < n ; i++ )
			cin >> A[i];
		int counti = 0 , countj = 0 , count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			counti += A[i] ;
			countj = 0 ;
			for ( int j = n-1 ; j >= 0 ; j-- )
			{
				countj += A[j] ;
				if ( countj > counti )
					break;
				else if ( countj == counti )
					count++;
			}
		}
		cout << count << endl;
	}
	return 0 ; 
}
