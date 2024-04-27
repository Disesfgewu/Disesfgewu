#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std ;

int main ()
{
	string s ;
	vector <string> d ;
	getline( cin , s ) ;
	int j = 0 ;
	string a ;
	for ( int i = 0 ; s[i] != '\0' ; ++i )
	{
		if ( s[i] == '+' && j == 0 )
		{	
			j = 1 ;
			d.push_back( a ) ;
			a = "" ;
		} 
		else if ( s[i] == '-' && j == 0 )
		{
			j = 2 ; 
			d.push_back( a ) ;
			a = "" ;
		}
		if ( ( s[i] == '+' || s[i] == '-' ) && j == 1 )
		{
			d.push_back( a ) ;
			a = "" ;
			if ( s[i] == '+' )
			{	
				j = 1 ;
			}
			else
			{	
				j = 2 ;
			} 
		}
		else if ( ( s[i] == '+' || s[i] == '-' ) && j == 2 )
		{
			reverse( a.begin() , a.end() ) ;
			d.push_back( a ) ;
			a = "" ;
			if ( s[i] == '+' )
			{	
				j = 1 ;
			}
			else
			{	
				j = 2 ;
			} 
		}
		else
		{
			a += s[i] ;
		}
	}
	if ( j <= 1 )
	{	
		d.push_back( a ) ;
	}
	else
	{
		reverse( a.begin() , a.end() ) ;
		d.push_back( a ) ;
	}
	for ( int it = 0 ; it < d.size() ; ++it )
	{
		cout << d[it] ;	
	}
	cout << endl ;
	return 0 ;
 }
