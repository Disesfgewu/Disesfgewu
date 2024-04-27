#include <bits/stdc++.h>
using namespace std ;
int main ()
{
	int n ;
	cin >> n ;
	int x = 0 , y = 0 , a , b ;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> a >> b ;
		switch(a)
		{
			case 0 :
				y += b ;
				break ;
			case 1 :
				x += b ;
				break;
			case 2 :
				y -= b ;
				break ;
			default :
				x -= b ;
				break ;
		}
	}
	cout << x << " " << y << endl;
}
