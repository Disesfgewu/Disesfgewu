#include <iostream>
using namespace std;
int main() 
{
	long long int a, b ,count = 0;
	cin >> a;
	while ( a > 0 ) 
	{
		cin >> b ;
		count += b;                                                                                                                                                                                                                                 
		cout << count << ' ';
		a--;
	}
	return 0;
}
