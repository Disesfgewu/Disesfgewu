#include <bits/stdc++.h>
using namespace std ;
const int nmax = 300005 ;
int a[nmax] = {0} , B[nmax] = {0} ;
int n ; 
int fmin ( int l ,int r )
{
	int count = a[l] , mmin = l ;
	for ( int i = l+1 ; i < r+1 ; ++i )
	{
		if ( count > a[i] )
		{
			count = a[i] ;
			mmin = i ;
		}
	}
	return mmin ;
 } 
int main ()
{
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ; 
	cin >> n ;
	cin >> a[0] ;
	B[0] = a[0] ;
	for ( int i = 1 ; i < n ; ++i )
	{
		cin >> a[i] ;
		B[i] = B[i-1]+a[i] ;
	}
	int L = 0 , R = n-1 , k = 0;
	while ( L != R )
	{
		int tmin = fmin( L , R ) ;
		if ( B[R] - B[tmin] >= B[tmin-1] - k )
		{
			L = tmin+1 ;
			k = B[tmin] ;
		}
		else
			R = tmin-1 ;
	}
	cout << a[R] << '\n';
	return 0 ;
 } 
