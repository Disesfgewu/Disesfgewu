#include <iostream>
using namespace std;
int main ()
{
	int h[2] = {0} , m[2] = {0} ;
	while ( cin >> h[0] >> m[0] >> h[1] >> m[1] )
	{
		int t1 = h[0] * 60 + m[0];
		int t2 = h[1] * 60 + m[1];
		if ( t1 < t2 )
			cout << (t2-t1)/60 << " " << (t2-t1)%60 << endl;
		else
		{
			int t3 = 24*60 - t1 + t2;
			cout << t3 / 60 << " "  << t3%60 << endl;
		}
	}
	return 0 ;
 } 
