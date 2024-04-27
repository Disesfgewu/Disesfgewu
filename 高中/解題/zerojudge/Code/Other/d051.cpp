#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	float N ;
	while ( cin >> N )
		cout << fixed <<  setprecision(3) << ( N-32 ) * 1.8  << endl;
	return 0 ;
 } 
