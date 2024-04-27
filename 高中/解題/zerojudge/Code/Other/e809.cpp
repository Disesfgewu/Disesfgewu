#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std ;
string n , s ;
int q ;
map <char,int> d ;
int main ()
{
	cin >> n ;
	for ( int i = 0 ; i < n.size() ; ++i )
	{
		d[n[i]] = i ;
	}
	int count[30] = {0} ;
	cin >> s ;
	for ( int i = 0 ; i < s.size() ; ++i )
		count[d[s[i]]]++ ;
	for ( int i = 1 ; i < n.size() ; ++i )
		count[i] += count[i-1] ;
	cin >> q ;
	while ( q-- )
	{
		int f ;
		cin >> f ;
		int it = lower_bound( count , count+n.size() , f ) - count ;
		cout << n[it] << endl;
	}
 } 
