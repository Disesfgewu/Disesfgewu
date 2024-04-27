#include <bits/stdc++.h>
using namespace std;
//ios::sync_with_stdio(false);
int x ;
int g ( int z )
{
	if ( z >= 2 )
		return pow(z,2)-1 ;
	else
		return 2 ;
}
int h ( int y )
{
	int a[] = { -1 , 2 , 5 , 5 , 2 };
	int u = y % 5 ;
	if ( u == 0 )
		return a[4] ;
	else
		return a[u-1] ;
}
int f ( int a )
{
	if ( a > h(a) )
		return f(a-1) - h(a) ;
	else if ( a < h(a) )
		return f(g(a)) - g(a);
	else
		return 1 ;
}
int main ()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	while ( cin >> x )
		printf( "%d\n" , f(x) );
	return 0 ;
}
