#include <iostream>
using namespace std ;
long long n[101]={0} ;
int main ()
{
	n[0]=1;
	n[1]=1;
	for ( int i = 2 ; i < 101 ; ++i )
		n[i] = n[i-1]+n[i-2] ;
	int t ;
	while ( cin >> t )
		cout << n[t] << endl ;
	return 0 ;
}
