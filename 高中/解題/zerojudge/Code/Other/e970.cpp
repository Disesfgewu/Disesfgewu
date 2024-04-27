#include <iostream>
//#include <vector>
using namespace std;
int main ()
{
	cin.tie( NULL ) ;
	cout.tie( NULL ) ;
	//vector < pair<int , int > > d ;
	int n ;
	cin >> n ; 
	int N[n] ;
	for ( int i = 0 ; i < n ; i++ )
		cin >> N[i] ;
	int count = 1 , ans = 0 ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		if ( i % N[n-1] == count )
		{
			ans += N[i-1] ;
		}
	}
	count = ans % n ;
	if ( count == 0 )
		cout << n << " " << N[n-1] << endl ;
	else
		cout << count << " " << N[count-1] << endl ; 
 } 
