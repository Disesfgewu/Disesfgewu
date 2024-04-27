#include <iostream>
using namespace std;
int n ;
int f ( int i )
{
	if ( i <= 1 )
	{
		cout << "1 = " ;
		return 1 ;
	}
	else 
	{
		cout << i << " * ";
		return f(i-1) * i;
	}
}
int main()
{
	while ( cin >> n )
	{
		cout << n << "! = " ;
		cout << f(n) << endl;
	}
	return 0 ;
}//0! = 1 = 1
