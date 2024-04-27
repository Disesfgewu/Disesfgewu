#include <iostream>
#include <cstring> 
#include <cmath>
#include <vector>
using namespace std;
vector <int> d ;
int a ( int n ) ;
int main () 
{
	cin.tie(0) ;
	cout.tie(0) ;
	long long n ;
	while (cin >> n )
	{
		long long u = n ;
		d.clear();
		while ( 1 )
		{
			if ( u == 1 )
			{
				cout << n <<" is a happy number" << endl;
				break;
			}
			long long  count = 0 ;
			while ( u > 0 )
			{
				count += pow( u%10 , 2 ) ;
				u /= 10 ;
			}
			u = a( count ) ;
			if ( u == 1 )
			{
				cout << n << " is an unhappy number" << endl;
				break ; 
			}
			else
			{
				d.push_back( count ) ;
				u = count ;
			}
		}
    }
}
int a ( int n )
{
	for ( int i = 0 ; i < d.size() ; i++ )
	{
		if ( d[i] == n )
			return 1 ;
	}
	return 0 ;
}
