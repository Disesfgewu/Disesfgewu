#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std ;
int main ()
{
	int n = 1 ;
	while ( n != 0 )
	{
		cin >> n ;
		if ( n == 0 )
			break ;
		vector < int > ans ;
		int ans2 = 0 , l = n , i = 0 ;
		
		while ( l != 0 )
		{
			int a = l % 2 ;
			l /= 2 ;
		//	cout << "a : " << a << endl ;
			ans.push_back( a ) ;
		//	cout << "ans : " << ans << endl; 
			ans2 += a ;
			i++ ;
		}
		//reverse( ans.begin() , ans.end() ) ;
		cout << "The parity of " ;
		for ( int i = ans.size() - 1 ; i >= 0 ; i-- )
			cout << ans[i] ; 
		cout << " is " << ans2 << " (mod 2).\n" ;
	}
	return 0 ;
}
