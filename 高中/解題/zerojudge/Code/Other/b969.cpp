#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main ()
{
	vector <string> p ;
	string s ;
	getline( cin , s ) ;
	string b ;
	stringstream input( s );
	string h ;
	getline( cin , h );
	while ( input >> b )
	{
		p.push_back( b ) ;
	}
	for ( int i = 0 ; i < p.size() ; i++ )
	{
		cout << h << ", " << p[i] << endl;
	}
}
