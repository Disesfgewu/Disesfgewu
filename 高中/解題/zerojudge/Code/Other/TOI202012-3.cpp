#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
int main ()
{
	string a , b ;
	string s = "FOR" , s2 = "for" , k = "YOU" , k2 = "you" , m = "to" , m2 = "To" , v = "and" , v2 = "AND";
	getline( cin , a );
	vector<string> res;
	stringstream input(a);
	while ( input >> b )
		res.push_back( b ) ;
	for ( int i = 0 ; i < res.size() ; i++ )
	{
		string d = res[i] ;
		if ( ( d[0] == s[0] || d[0] == s2[0] ) && ( d[1] == s[1] || d[1] == s2[1] ) && ( d[2] == s[2] || d[2] == s2[2] ) && d.size() == 3 )
			cout << "4" ;
		else if ( ( d[0] == k[0] || d[0] == k2[0] ) && ( d[1] == k[1] || d[1] == k2[1] ) && ( d[2] == k[2] || d[2] == k2[2] ) && d.size() == 3 )
			cout << "u" ;
		else if ( ( d[0] == m[0] || d[0] == m2[0] ) && ( d[1] == m[1] || d[1] == m2[1] ) && d.size() == 2 )
			cout << "2" ;
		else if ( ( d[0] == v[0] || d[0] == v2[0] ) && ( d[1] == v[1] || d[1] == v2[1] ) && ( d[2] == v[2] || d[2] == v2[2] ) && d.size() == 3 )
			cout << "n" ;
		else
		{
			if ( int( d[0] ) > 90 )
				d[0] -= 32 ;
			cout << d[0] ;
		}
	}
	cout << '\n' ;
}
