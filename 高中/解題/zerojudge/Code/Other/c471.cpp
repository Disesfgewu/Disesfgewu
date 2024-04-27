#include <iostream>
#include <algorithm>
using namespace std ;
struct bo{
	long long w ;
	long long f ;
};
bool cmp ( bo a , bo b )
{
	return b.f*a.w < a.f*b.w ;
}
int main ()
{
	int n ;
	while(cin >> n ){
	bo X[n] ;
	for ( int i = 0 ; i < n ; ++i )
		cin >> X[i].w ;
	for ( int i = 0 ; i < n ; ++i )
		cin >> X[i].f ;
	sort( X , X+n , cmp ) ;
	long long ans = 0 , Wsum = 0 ;
	for ( int i = 0 ; i < n-1 ; ++i )
	{
		Wsum += X[i].w ;
		ans += X[i+1].f*Wsum ;
	}
	cout << ans << endl ;
	}
	return 0 ;
 }
