#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>\
//#define first f
//#define second s
using namespace std;
int main ()
{
	
	string s ;
	while (  getline( cin , s ) )
	{
	vector < pair< char , int > > d ;
	char a ;
	a = s[0] ;
	int count = 0 ;
	for ( int i = 0 ; i < s.size() ; i++ )
	{
		count++ ;
		if ( a != s[i] )
		{
			pair < char , int > q ;
			q.first = a ;
			q.second = count-1 ;
			d.push_back( q ) ;
			count = 1 ;
			a = s[i] ;
		}
	}
	int mmax = 0 ;
	for ( int i = 0 ; i < d.size() ; i++ )
	{
		mmax = max( mmax , d[i].second );
	}
	for ( int i = 0 ; i < d.size() ; i++ )
	{
		if ( d[i].second == mmax )
		{
			cout << d[i].first << " " << mmax << endl ;
			break;
		 } 
	}
	}
}
