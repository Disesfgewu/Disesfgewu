#include <iostream>
using namespace std;
int a[10000000] = {0} , n ;
int main ()
{
	cin >> n ;
	int i ;
	for ( i = 0 ; i < n ; i++ )
	{
		int f , b ;
		cin >> f >> b ;
		int j ;
		for ( j = f ; j < b ; j++ )
			a[j] = 1 ;
	}
	int count = 0 ;
	for ( i = 0 ; i < 10000000 ; i++ )
		if ( a[i] == 1 )
			count++ ;
	cout << count << endl;;
}
