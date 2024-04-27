#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n ;
	while ( cin >> n )
	{
		int h[n] ={0};
		for ( int i = 0 ; i < n ; i++ )
			cin >> h[i];
		sort( h , h+n );
		for ( int i = 0 ; i < n ; i++ )
			cout << h[i] << " ";
		cout << endl;
	}
	return 0 ;
}
