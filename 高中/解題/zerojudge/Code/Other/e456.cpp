#include <iostream>
#include <vector>
#include <sstream>
using namespace std ; 
int n = 0;
string s ;
vector <string> d;
int main() 
{
	while( !cin.eof() && cin >> s )
		d.push_back( s ) ;
	for(int i = 0; i < d.size()-1 ; ++i)
		cout << d[i] <<" little, " ;
	cout << d[d.size()-1] << " little Indians\n";
	
	return 0;
}
