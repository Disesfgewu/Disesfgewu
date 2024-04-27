#include <iostream>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
vector <int> st ;
int n , h ;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	cin >> n ;
	while ( n-- )
	{
		cin >> h ;
		st.push_back( h ) ;
	}
	int count , ans = 0 ;
	for ( int i = st.size()-1 ; i >= 0 ; i-- )
	{
		count = INT_MAX ;
		for ( int j = 0 ; j <= i ; j++ )
			if ( st[j] < count )
				count = st[j] ;	
		//cout << count << " " << ans << " " << i << endl ;
		ans = max( ans , count*( i+1 ) ) ;
	//	cout << ans << endl ;
	}
	cout << ans << endl;
}
