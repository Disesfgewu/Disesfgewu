#include <bits/stdc++.h> 
using namespace std;
vector <string> d ;
bool check ( string s )
{
	auto count = find( d.begin() , d.end() , s ) - d.begin(); 
	if ( count == d.size() )
	{
		d.push_back( s ) ;
		return false ;
	}
	else
		return true ;

}
int main ()
{
	string s ;
	while ( cin >> s && !cin.eof() )
		cout << check( s ) << endl; 
	return 0 ;
}
