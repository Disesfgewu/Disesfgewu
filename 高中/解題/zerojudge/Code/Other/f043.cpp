#include <iostream>
using namespace std;
int main ()
{
	int a , b ;
	cin >> a >> b ;
	if ( a == b )
		b -= 3 ;
	if ( a-b < b )
			cout << a-b << "+" << b << "=" << a << endl;
		else
			cout << b << "+" << a-b << "=" << a << endl;
 } 
