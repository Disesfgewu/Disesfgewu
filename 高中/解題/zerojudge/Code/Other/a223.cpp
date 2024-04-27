#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int N ;
	while ( cin >> N )
	{
		int a[N] = {0};
		for ( int i = 0 ; i < N ; i++ )
			cin >> a[i];
		sort( a , a+ N );
		for ( int i = 0 ; i < N ; i++ )
			cout << a[i] << " ";
		cout << '\n';
	 }  
	return 0 ;
}
