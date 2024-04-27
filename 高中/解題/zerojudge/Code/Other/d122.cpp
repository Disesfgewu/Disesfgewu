#include <iostream>
using namespace std;
int main ()
{
	long int N;
	while ( cin >> N )
	{
		int count = 0 ;
		do
		{
			N /= 5 ;
			count += N ;
		}while ( N != 0 );
		cout << count << endl;
	}
	return 0 ;
} 
