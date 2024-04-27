#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std ;
int main ()
{
	int n;
	while ( cin >> n )
	{
		int a[n] = {0} , b[n] = {0} , c[n] = {0} ;
		for ( int i = 0 ; i < n ; i++ )
			cin >> a[i] ;
		int count = INT_MAX , j = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> b[i] ;
			c[i] = a[i] * b[i] ;
			if ( count > c[i] )
			{
				count = c[i] ;
				j = i ;
			 } 
		}
		cout << a[j] <<" " << b[j] << endl ;
	}
 } 
