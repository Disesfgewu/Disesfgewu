#include <bits/stdc++.h>
using namespace std ;
const int nmax = 46342 ;
bool a[nmax] ;
vector <int> w ;
int main ()
{
	int n ;
	for ( int i = 2 ; i < nmax ;  ++i )
	{
		if ( !a[i] )
		{ 
			w.push_back( i ) ;
			for ( int j = i*i ; j < nmax ; j += i )
				a[j] = true ;
		}
	}
	while ( cin >> n )
	{
		if ( n > 46341 )
		{
			bool flag = true ;
			for ( int i : w )
			{
				if ( n % i == 0 )
				{
					cout << "獶借计\n" ;
					flag = false ;
					break ;
				}
			}
			if ( flag )
				cout << "借计\n" ;
		}
		else
		{
			if ( !a[n] )
				cout << "借计\n" ;
			else
				cout << "獶借计\n" ;
		}
	}
	return 0 ;
 } 
