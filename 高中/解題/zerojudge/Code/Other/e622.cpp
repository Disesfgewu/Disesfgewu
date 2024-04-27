#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main ()
{
	int n , s;
	while ( cin >> n >> s )
	{
		vector <int> cp ;
		vector <int> iv ;
		int a , b ;
		while ( scanf("%d %d",&a , &b ) != EOF )
		{
			cp.push_back(a);
			iv.push_back(b);
		}
		int count = s / 1000 ;
		a = 0 ;
		b = 0 ;
		for ( int i = 0 ; i < cp.size() ; i++ )
		{
			if( iv[i] >= 0 && iv[i] <= 29 )
				cp[i] += 10*count ;
			else if( iv[i] >= 30 && iv[i] <= 39 )
				cp[i] += 50*count ;
			else
				cp[i] += 100*count ;
			if ( cp[i] > a )
			{
				a = cp[i];
				b = i+1 ;
			}
		}
		cout << b << " " << a << endl;
	}
	return 0 ;
 } 
