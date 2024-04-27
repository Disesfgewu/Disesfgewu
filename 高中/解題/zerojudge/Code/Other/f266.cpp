#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main ()
{
	vector <string> k ;
	string s , b ;
	getline( cin , s ) ;
	stringstream input( s ) ;
	while ( input >> b )
	{
		k.push_back( b ) ;
	}
	int y = k.size() ;
	for ( int i = 0 ; i < y ; i++ )
	{
		for ( int j = i ; j < k.size() ; j++ )
		{
			cout << k[j] << " " ; 
		}
		cout << endl;
		//k.pop() ;
	}
}
