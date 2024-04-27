#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int d1[1001] = {0} ,  d2[1001] = {0} ;
	int a , b ;
	cin >> a ;
	for ( int i = 0 ; i < a ; i++ )
	{
		int q ,w ;
		cin >> q >> w ;
		d1[q] = w ;
	}
	cin >> b ;
	for ( int i = 0 ; i < b ; i++ )
	{
		int q ,w ;
		cin >> q >> w ;
		d2[q] = w;
	}
	int q[1001] = {0} ;
	for ( int i = 0 ; i <= 1000 ; i++ )
	{
		if ( d1[i] == 0  && d2[i] == 0 )
			continue ;
		else
			q[i] = d1[i] + d2[i];
	}
	int count = 0 ;
	for ( int i = 1000 ; i >= 0 ; i-- )
	{
		if ( q[i] != 0 )
		{
			cout << i << ":" << q[i] << endl;
			count = 1 ;
		}
	}
	if ( count == 0 )
		cout << "NULL!" << endl;
}
