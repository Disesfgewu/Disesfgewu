#include <bits/stdc++.h>
using namespace std;
int main ()
{
	long long int n ;
	while ( cin >> n )
	{
	n /= 2 ;
	long long int count = 0 ;
	for ( long long int i = 1 ; i < n ; i++ )
		count = max ( count ,i*n - i*i ) ;
	cout << count << endl;
 }
 return 0 ; 
}
