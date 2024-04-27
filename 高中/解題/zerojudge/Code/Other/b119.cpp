#include <iostream>
using namespace std;
int s = 0 ;
int C2 ( int n )
{
	return n* ( s / 100 * 70 );
}
int C4 ( int n )
{
	return n*(s / 100 * 80 );
}
int C6 ( int n )
{
	return n*(s / 100 * 90 );
}
int CALL ( int n )
{
	return n * s; 
 } 

int main ()
{
	int t , n;
	while ( cin >> s >> t >> n )
	{
		int count = 0 ;
		for ( int i = 0 ; i < n ; i++ )
		{
			int y ;
			cin >> y ;
			count += y ;
		}
		float C20 , C40 , C60;
		C20 = t / 100 * 20 ;
		C40 = t / 100 * 40 ;
		C60 = t / 100 * 60 ;
		int c = 0 ;
		if ( count > 0 && count <= C20 )
		{
			c += C2(count);
		}
		else if (count > C20 && count <= C40)
		{
			c = c + C2(C20) + C4(count-C20);
		}
		else if ( count > C40 && count <= C60)
		{
			c = c + C2(C20) + C4(C40-C20) + C6(count-C40); 
		}
		else
		{
			c = c + C2(C20) + C4(C40-C20) + C6(C60-C40) + CALL(count-C60); 
		}
		cout << c - s*(t/100*30) << endl; 
	}
	return 0 ;
}
