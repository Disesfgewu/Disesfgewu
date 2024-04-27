#include <iostream>
using namespace std;
int a[10000] = {0};
int main () 
{
	int n ;
	while( cin >> n )
	{
		int b;
		for ( int i = 0 ; i < n ; i++ )
		{
			cin >> b ;
			a[b]++;
		}
		b = 0 ;
		int u = 0 ;
		for ( int i = 0 ; i < 10000 ; i++ )
			if ( b < a[i] )
				b = a[i] , u = i  ;
		cout << u <<" "<< b << endl; 
	}
	return 0 ;
}
