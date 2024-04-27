#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	vector <int> d ;
	int s ;
	do
	{
		cin >> s ;
		d.push_back( s ) ;
	}while ( s != -1 ) ;
	sort( d.begin() , d.end() );
	cin >> s ;
	cout << d[d.size()-s] << endl;
}
